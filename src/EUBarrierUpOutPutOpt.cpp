#include "EUBarrierUpOutPutOpt.h"
#include "Path.h"
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
	double barrier = paras.g_VAL<double>("barrier");
	Path* path_ = paras.g_PTR<Path>("path");
	bool bTriggerBarrier = path_->break_up(barrier);
	if (bTriggerBarrier)
	{
		return 0.0;
	}
	else
	{
		return UF::max(0.0, K_ - paras.g_VAL<double>("ST"));
	}
}