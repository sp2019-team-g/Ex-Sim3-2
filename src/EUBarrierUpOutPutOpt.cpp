#include "EUBarrierUpOutPutOpt.h"

#include "Util.h"
EUBarrierUpOutPutOpt::EUBarrierUpOutPutOpt(double T, double K) : Option(T)
{
	K_ = K;
}

EUBarrierUpOutPutOpt::EUBarrierUpOutPutOpt(Arguments& paras) : Option(paras)
{
	K_ = paras.g_VAL<double>("K");
}

double EUBarrierUpOutPutOpt::payoff(Arguments& paras)
{
	if (paras.has("UP_REACH") && paras.g_VAL<bool>("UP_REACH"))
	{
		return 0.0;
	}
	else
	{
		return UF::max(0.0, K_ - paras.g_VAL<double>("ST"));
	}
}