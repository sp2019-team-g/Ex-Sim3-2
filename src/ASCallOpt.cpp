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

double ASCallOpt::payoff(Arguments &paras)
{
    Path *path = new Path(paras);
	double t = path->arithmeticAvg();
	return UF::max(t - K_, 0.0);
}
