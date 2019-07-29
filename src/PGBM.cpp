
#include "PGBM.h"

<<<<<<< Updated upstream



=======
>>>>>>> Stashed changes
PGBM::PGBM(double dt,double mu,double sigma) : Process(dt)
{
	mu_ = mu;
	sigma_ = sigma;
	set_loaded(false);
}

PGBM::PGBM(Arguments& paras) : Process(paras)
{
	mu_ = paras.g_VAL<double>("mu");
	sigma_ = paras.g_VAL<double>("sigma");
	try
	{
		S0_ = paras.g_VAL<double>("S0");
		set_loaded(true);
	}
	catch(...)
	{
		set_loaded(false);
	}
	post_update();
}

void PGBM::post_update(){}

void PGBM::para_load(Arguments& paras)
{
	S0_ = paras.g_VAL<double>("S0");
	set_loaded(true);
	post_update();
}

double PGBM::simulate()
{
	double T = get_dt();
	return S0_*std::exp((mu_-sigma_*sigma_/2.0)*T + sigma_*UF::normalRnd(0,T));
}

double PGBM::simulate(Arguments& paras)
{
	para_load(paras);
	double* res = new double(simulate());
	paras.g_SET<double>("ST", res);
	return *res;
}
