#include "ASCallOpt.h"
#include "Path.h"
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
	Path* path_ = paras.g_PTR<Path>("path");

	return UF::max(0.0, path_->arithmeticAvg() - K_);
}
