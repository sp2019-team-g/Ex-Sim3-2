#include "Option.h"
// #include <iostream>
// using namespace std;
Option::Option(double T)
{
	T_ = T;
}

Option::Option(double T, std::function<double(Arguments&)>* pf)
{
	T_ = T;
	payoff_ = pf;
}

Option::Option(Arguments& paras)
{
	// cout<<"yyyy"<<endl;
	T_ = paras.g_VAL<double>("T");
	try
	{
		payoff_ = paras.g_PTR<std::function<double(Arguments&)> >("payoff");
	}
	catch(...){}
}

double Option::get_T()
{
	return T_;
}

double Option::payoff(Arguments& paras){
	return payoff_->operator()(paras);
}

