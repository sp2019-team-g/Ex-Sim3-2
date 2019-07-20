#ifndef PRICINGENG_EX32_H
#define PRICINGENG_EX32_H

#include "Arguments.h"
#include "Option.h"
class PricingEng{
	public:
		PricingEng(Option*);
		PricingEng(Arguments);
		virtual double price(){return 0.0;}
		virtual double price(Arguments){return 0.0;}
	protected:
		Option* opt_;
};


#endif
