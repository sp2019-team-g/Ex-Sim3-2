
#include "McPricingEng.h"


McPricingEng::McPricingEng(Option*opt, Process*pro) : PricingEng(opt)
{
	pro_ = pro;
}

McPricingEng::McPricingEng(Arguments& paras) : PricingEng(paras)
{
	pro_ = paras.g_PTR<Process>("process");
}

double McPricingEng::price()
{
	throw std::runtime_error("error");
}

double McPricingEng::price(Arguments& paras)
{
	double bsize = (double)paras.g_VAL<size_t>("batch_size");

	double T = paras.g_VAL<double>("T");

	double res = 0.0;

	for(double i = 0;i<bsize;i=i+1.0)
	{

		pro_->simulate(paras);
		res += opt_->payoff(paras)*std::exp(-T)/T;
	}
	return res;
}
