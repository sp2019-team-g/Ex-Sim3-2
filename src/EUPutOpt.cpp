#include "EUPutOpt.h"
#include "Arguments.h"
#include "Util.h"

EUPutOpt::EUPutOpt(double T, double K) : Option(T)
{
	K_ = K;
}

EUPutOpt::EUPutOpt(Arguments& paras) : Option(paras)
{
	K_ = paras.g_VAL<double>("K");
	paras.g_SET<bool>("simp", new bool(true));
}

double EUPutOpt::payoff(Arguments& paras)
{
	return UF::max(0.0, K_ - paras.g_VAL<double>("ST"));
}
