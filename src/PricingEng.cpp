

#include "PricingEng.h"

PricingEng::PricingEng(Arguments paras)
{
	pss_ = __ARG_PTR("process", Process, paras);
	opt_ = __ARG_PTR("option", Option, paras);
	if(!pss_->check_loaded())
		pss_->para_laod(paras);
	t_ = 0;
}

double simulate(Arguments paras)
{
	size_t batch_size = __ARG_VAL("bsize", size_t, paras);
	double sum = 0.0;
	// double* ST = new double(0.0);
	// paras.set("ST",(void*)ST);
	for(size_t i=0;i<batch_size;i++)
	{
		pss_.simulate(paras);
		sum += opt_.payoff(paras);
	}
	return sum/(double)batch_size;
}

double pathSimulate(Arguments paras)
{
	double dt = __ARG_VAL("dt", double, paras);
	size_t batch_size = __ARG_VAL("bsize", size_t, paras);
		

}