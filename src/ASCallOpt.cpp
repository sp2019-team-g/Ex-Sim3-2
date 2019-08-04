#include "ASCallOpt.h"

#include "Util.h"
ASCallOpt::ASCallOpt(double T, double K) : Option(T)
{
	K_ = K;
}

ASCallOpt::ASCallOpt(Arguments& paras) : Option(paras)
{
	K_ = paras.g_VAL<double>("K");
}

double ASCallOpt::payoff(Arguments& paras)
{
	return UF::max(0.0, paras.g_VAL<double>("ST_AVER") - K_);
}
