#ifndef MCPRICINGENG_EX32_H
#define MCPRICINGENG_EX32_H

#include "PricingEng.h"
#include "Arguments.h"

class Option;
class Process;

class McPricingEng : public PricingEng
{
	public:
		McPricingEng(Option*, Process*);
		McPricingEng(Arguments&);
		double price();
		double price(Arguments&);
		static PLIST plist()
		{
			PLIST res;
			res.push_back(g_ASK<size_t>("batch_size"));
			res.push_back(g_ASK<double>("T"));
			return res;
		}

	private:
		Process* pro_;
};


#endif
