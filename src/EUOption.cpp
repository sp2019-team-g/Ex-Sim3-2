#include "EUOption.h"


#include "Util.h"
EUOption::EUOption(double T, double K, std::string cp) : Option(T)
{
    K_ = K;
    cp_ = cp;
}

EUOption::EUOption(Arguments& paras) : Option(paras)
{
    K_ = paras.g_VAL<double>("K");
    cp_ = paras.g_VAL<std::string>("CP");
    paras.g_SET<bool>("simp", new bool(true));
}

double EUOption::payoff(Arguments& paras)
{
	if(cp_ == "CALL")
    	return UF::max(0.0, paras.g_VAL<double>("ST") - K_);
    if(cp_ == "PUT")
    	return UF::max(0.0, K_ - paras.g_VAL<double>("ST"));
    throw OPTCPException();
}
