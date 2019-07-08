#include "Option.h"

Option::Option(double K, double T)
{
	K_ = K;
	T_ = T;
}

double Option::get_T()
{
	return T_;
}

double Option::get_K(){
	return K_;
}