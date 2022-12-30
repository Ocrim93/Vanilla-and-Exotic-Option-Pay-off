#include <iostream>
#include "MonteCarlo.cpp"


int main(){

	cout<< "Hello Mirco!"<< endl;

	double Expiry = 1.0;
	double Strike = 50.0;
	double Spot = 60.0;
	double Volatility = 0.2;
	double r = 0.05;
	long unsigned NumberOfPaths =  1000;

	double lower = 45;
	double upper = 75;
	PayOffCall  callPayOff(Strike);
	PayOffPut putPayOff(Strike);
	PayOffDoubleDigital doubleDigital(lower,upper);

	double callOptionPrice = SimpleMonteCarlo(callPayOff, Expiry,Spot,Volatility,r,NumberOfPaths);
	double putOptionPrice = SimpleMonteCarlo(putPayOff, Expiry,Spot,Volatility,r,NumberOfPaths);
	double DoubleDigitalOptionPrice = SimpleMonteCarlo(doubleDigital, Expiry,Spot,Volatility,r,NumberOfPaths);

	cout << "the call option price is " << callOptionPrice << "\n";
	cout << "the put option price is " << putOptionPrice << "\n";
	cout << "the Double Digital Option Price  is " << DoubleDigitalOptionPrice << "\n";

	return 0;



}