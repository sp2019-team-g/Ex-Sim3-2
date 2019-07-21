

#include "PricingEng.h"

PricingEng::PricingEng(Option*opt)
{
	opt_ = opt;
}

PricingEng::PricingEng(Arguments paras)
{
	opt_ = __ARG_PTR("option", Option, paras);
}

