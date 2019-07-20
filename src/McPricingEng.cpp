
#include "McPricingEng"

McPricingEng::McPricingEng(Option*opt,Process*pro):PricingEng(opt)
{
	pro_ = pro;
}

McPricingEng::McPricingEng(Arguments paras):PricingEng(paras)
{
	pro_ = __ARG_PTR("process", Process, paras);
}

double McPricingEng::price()
{
	throw std::runtime_error("error");
}

double McPricingEng::price(Arguments paras)
{

}