
#include "McPricingEng.h"

McPricingEng::McPricingEng(Option*opt, Process*pro):PricingEng(opt)
{
	pro_ = pro;
}

McPricingEng::McPricingEng(Arguments& paras):PricingEng(paras)
{
	pro_ = __ARG_PTR("process", Process, paras);
}

double McPricingEng::price()
{
	throw std::runtime_error("error");
}

double McPricingEng::price(Arguments& paras)
{
	double bsize = (double)__ARG_VAL("batch_size",size_t,paras);
	double T = __ARG_VAL("T",double,paras);
	double res = 0.0;
	for(double i = 0;i<bsize;i=i+1.0)
	{
		pro_->simulate(paras);
		res += opt_->payoff(paras)*std::exp(-T)/T;
	}
	return res;
}
