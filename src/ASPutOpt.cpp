#include "ASPutOpt.h"

#include "Util.h"
ASPutOpt::ASPutOpt(double T, double K) : Option(T)
{
	K_ = K;
}

ASPutOpt::ASPutOpt(Arguments& paras) : Option(paras)
{
	K_ = paras.g_VAL<double>("K");
}

double ASPutOpt::payoff(Arguments& paras)
{
	return UF::max(0.0, K_ - paras.g_VAL<double>("ST_AVER"));
}
