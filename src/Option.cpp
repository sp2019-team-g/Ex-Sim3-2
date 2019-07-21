#include "Option.h"

Option::Option(double T)
{
	T_ = T;
}

Option::Option(double T, std::function<double(Arguments&)>* pf)
{
	T_ = T;
	payoff_ = pf;
}

Option::Option(Arguments &paras)
{
	T_ = paras.g_VAL<double>("T");
	payoff_ = paras.g_PTR<std::function<double(Arguments&)> >("payoff");
}

double Option::get_T()
{
	return T_;
}

double Option::payoff(Arguments &paras){
	return payoff_->operator()(paras);
}