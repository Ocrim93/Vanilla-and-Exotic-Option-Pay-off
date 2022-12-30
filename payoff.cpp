#include "payoff.h"
#include <algorithm> 

PayOffCall::PayOffCall(double Strike_): Strike(Strike_)
//But if x, y & z are classes, then this is the only way to pass parameters into their constructors
{
	}

double PayOffCall::operator() (double spot) const{
	return std::max(spot-Strike,0.0);
}


PayOffPut::PayOffPut(double Strike_): Strike(Strike_)
//But if x, y & z are classes, then this is the only way to pass parameters into their constructors
{
	}

double PayOffPut::operator() (double spot) const{
	return std::max(Strike - spot, 0.0);
}


PayOffDoubleDigital :: PayOffDoubleDigital(double LowerLevel_,double UpperLevel_)
: LowerLevel(LowerLevel_),UpperLevel(UpperLevel_)
{

}

double PayOffDoubleDigital::operator() (double spot) const{
	if(spot <= LowerLevel)
		return 0;
	if (spot >= UpperLevel)
		return 0;
	return 1;
}