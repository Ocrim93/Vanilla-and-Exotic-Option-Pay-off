#include <iostream>
#include <cmath>

#include "payoff.cpp"
#include "Random.cpp"

using namespace std;
// without & the program will create a new  object with the same value of the passed object 
// if you remove the &, the compiler gives you an error because you cannot create an object of a type with a pure virtual method
// there are two ways to forget the type of the object 1) reference or pointer  
double SimpleMonteCarlo(const PayOff& thePayOff,
						double Expiry,
						double Spot,
						double Volatility,
						double r,
						long unsigned NumberOfPaths){


	double variance = Volatility*Volatility*Expiry;
	double rootVariance = sqrt(variance);
	double itoCorrection = -0.5*variance;

	double movedSpot = Spot*exp(r*Expiry+itoCorrection);
	double thisSpot;
	double runningSum=0;
	
	for (unsigned long i = 0;i< NumberOfPaths;i++){
		double thisGaussian  = GetOneGaussianyBoxMuller();
		thisSpot = movedSpot*exp(rootVariance*thisGaussian);
		double thisPayoff = thePayOff(thisSpot);
		thisPayoff = thisPayoff > 0 ? thisPayoff : 0;
		runningSum += thisPayoff;
	}
	double mean = runningSum/NumberOfPaths;
	mean *= exp(-r*Expiry);
	return mean;

}


