#include "Option.h"

Option::Option(double K, double T, std::function<double(Arguments)>* pf)
{
	K_ = K;
	T_ = T;
	payoff_ = pf;
}

Option::Option(Arguments paras)
{
	K_ = __ARG_VAL("K", double, paras);
	T_ = __ARG_VAL("T", double, paras);
	payoff_ = __ARG_PTR("payoff", std::function<double(Arguments)>, paras);
}

double Option::get_T()
{
	return T_;
}

double Option::get_K(){
	return K_;
}

double Option::payoff(Arguments paras){
	return payoff_->operator()(paras);
}