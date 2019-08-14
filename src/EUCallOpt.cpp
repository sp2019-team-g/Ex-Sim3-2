
#include "EUCallOpt.h"

#include "Util.h"
EUCallOpt::EUCallOpt(double T, double K) : Option(T)
{
    K_ = K;
}

EUCallOpt::EUCallOpt(Arguments& paras) : Option(paras)
{
    K_ = paras.g_VAL<double>("K");
    paras.g_SET<bool>("simp", new bool(true));
}

double EUCallOpt::payoff(Arguments& paras)
{
    return UF::max(0.0, paras.g_VAL<double>("ST") - K_);
}

