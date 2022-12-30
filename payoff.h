#ifndef PAYOFF_H
#define PAYOFF_H

class PayOff{

	public:
		
		PayOff(){};
		virtual ~PayOff(){}
		//overloading operator()
		// if we define a Payoff object const , we cannot call a non const method --> Error
		//
		virtual double operator()( double Spot ) const = 0;

	private: 

};

class PayOffCall : public PayOff{
	public:
		PayOffCall(double Strike_);
		virtual double operator()( double Spot ) const;
		virtual ~PayOffCall(){};

	private:
		double Strike;	 
};

class PayOffPut : public PayOff{
	public:
		PayOffPut(double Strike_);
		virtual double operator()( double Spot ) const;
		virtual ~PayOffPut(){};

	private:
		double Strike;	 
};

// DoubleDigital payOff . It pays 1 if spot is between two values and 0 otherwise
class PayOffDoubleDigital : public PayOff{
	public: 
		PayOffDoubleDigital(double LowerLevel_,double UpperLevel_);
		virtual ~PayOffDoubleDigital(){}
		virtual double operator()( double Spot ) const ;
	private:
		double LowerLevel;
		double UpperLevel;



};

#endif