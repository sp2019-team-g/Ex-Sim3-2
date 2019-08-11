#include "EUBarrierUpOutCallOpt.h"
#include "Path.h"
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
	double barrier = paras.g_VAL<double>("barrier");
	Path* path_ = paras.g_PTR<Path>("path");
	bool bTriggerBarrier = path_->break_up(barrier);

	if (bTriggerBarrier)
	{
		return 0.0; 
	}
	else
	{
		return UF::max(0.0, paras.g_VAL<double>("ST") - K_);
	}
}
