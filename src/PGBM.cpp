
#include "PGBM.h"

PGBM::PGBM(double dt,double mu,double sigma):Process(dt)
{
	mu_ = mu;
	sigma_ = sigma;
	set_loaded(false);
}

PGBM::PGBM(Arguments paras):Process(paras)
{
	mu_ = __ARG_VAL("mu", double, paras);
	sigma_ = __ARG_VAL("sigma", double, paras);
	try
	{
		S0_ = __ARG_VAL("S0",double,paras);
		set_loaded(true);
	}
	catch(...)
	{
		set_loaded(false);
	}
	post_update();
}

void PGBM::post_update(){}

void PGBM::para_load(Arguments paras)
{
	S0_ = __ARG_VAL("S0", double, paras);
	set_loaded(true);
	post_update();
}

double PGBM::simulate()
{
	double T = get_dt();
	return S0_*std::exp((mu_-sigma_*sigma_/2.0)*T + sigma_*UF::normalRng(0,T));
}

double PGBM::simulate(Arguments paras)
{
	para_load(paras);
	double* res = new double(simulate());
	__ARG_SET("ST", res, paras);
	return *res;
}
