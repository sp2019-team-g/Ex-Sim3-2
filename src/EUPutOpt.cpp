
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
}

double EUPutOpt::payoff(Arguments& paras)
{
	return UF::max<double>(0.0, paras.g_VAL<double>("ST") - K_);
}
