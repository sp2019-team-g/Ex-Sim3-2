#ifndef PRICINGENG_EX32_H
#define PRICINGENG_EX32_H

#include "Arguments.h"
#include "Process.h"
class PricingEng{
	public:
		PricingEng(Arguments);
		double simulate(Arguments);
		double pathSimulate(Arguments);
		double closeForm(Arguments);
	private:
		Process* pss_;
		Option* opt_;
		double t_;
};





#endif
