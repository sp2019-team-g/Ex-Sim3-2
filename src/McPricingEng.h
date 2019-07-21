#ifndef MCPRICINGENG_EX32_H
#define MCPRICINGENG_EX32_H

#include "PricingEng.h"
#include <stdexcept>
class McPricingEng:public PricingEng{
	public:
		McPricingEng(Option*,Process*);
		McPricingEng(Arguments&);
		double price();
		double price(Arguments&);
	private:
		Process*pro_;
};


#endif
