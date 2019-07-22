#ifndef FACTORY_EX32_H
#define FACTORY_EX32_H

#include "Arguments.h"
#include "Process.h"
#include "PricingEng.h"
#include "Option.h"

template<class PS,class PE,class OP>
class Factory{
	public:
		Factory();
		void buildArg();
		PricingEng* build();
	private:
		Arguments arg;
};




#endif
