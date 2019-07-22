#ifndef FACTORY_EX32_H
#define FACTORY_EX32_H

#include "Arguments.h"
#include "Process.h"
#include "PricingEng.h"
#include "Option.h"

#include <vector>


template<class PS,class PE,class OP>
class Factory{
	public:
		Factory()
		{
			arg_ = 
		}

		void build()
		{

		}
	private:
		Arguments arg_;
		Process* ps_;
		PricingEng* pe_;
		Option* op_;

};




#endif
