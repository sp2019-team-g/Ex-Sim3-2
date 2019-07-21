#ifndef MCPRICINGENG_EX32_H
#define MCPRICINGENG_EX32_H

#include "PricingEng.h"
#include "Arguments.h"

#include <functional>
#include <vector>
#include <stdexcept>
class McPricingEng:public PricingEng{
	public:
		McPricingEng(Option*, Process*);
		McPricingEng(Arguments&);
		double price();
		double price(Arguments&);
		static std::vector<std::function<void(Arguments&)> >plist()
		{
			std::vector<std::function<void(Arguments)> > res();
			res.push_back(g_ASK<size_t>("batch_size"));
			res.push_back(g_ASK<double>("T"));
			return res;
		}
	private:
		Process*pro_;
};


#endif
