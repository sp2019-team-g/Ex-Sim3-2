
#include "EUCallOpt.h"

#include "Util.h"
EUCallOpt::EUCallOpt(double T, double K) : Option(T)
{
    K_ = K;
}

EUCallOpt::EUCallOpt(Arguments& paras) : Option(paras)
{
    K_ = paras.g_VAL<double>("K");
}

double EUCallOpt::payoff(Arguments& paras)
{
    return UF::max<double>(0.0, K_ - paras.g_VAL<double>("ST"));
}

