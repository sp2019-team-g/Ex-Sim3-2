#include "EUBarrierUpOutCallOpt.h"

#include "Util.h"
EUBarrierUpOutCallOpt::EUBarrierUpOutCallOpt(double T, double K) : Option(T)
{
	K_ = K;
}

EUBarrierUpOutCallOpt::EUBarrierUpOutCallOpt(Arguments& paras) : Option(paras)
{
	K_ = paras.g_VAL<double>("K");
}

double EUBarrierUpOutCallOpt::payoff(Arguments& paras)
{
	if (paras.has("UP_REACH") && paras.g_VAL<bool>("UP_REACH"))
	{
		return 0.0;
	}
	else
	{
		return UF::max(0.0, paras.g_VAL<double>("ST") - K_);
	}
}
