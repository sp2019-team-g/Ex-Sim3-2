#include "ASPutOpt.h"

#include "Path.h"
#include "Util.h"
ASPutOpt::ASPutOpt(double T, double K) : Option(T)
{
	K_ = K;
}

ASPutOpt::ASPutOpt(Arguments& paras) : Option(paras)
{
	K_ = paras.g_VAL<double>("K");
}

double ASPutOpt::payoff(Arguments &paras)
{
    Path *path = new Path(paras);
	double t = path->arithmeticAvg();
	return UF::max(K_ - t, 0.0);
}

