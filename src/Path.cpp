#include "Path.h"
Path::Path(double t, double dt, double T, std::vector<double> path)
{
	t_ = t;
	dt_ = dt;
	T_ = T;
	path_ = path;
}

// Path::Path(Arguments paras)
// {
// 	double S0 = __ARG_VAL("S0", double, paras);
// 	double St = S0;
// 	t_ = __ARG_VAL("t", double, paras);
// 	T_ = __ARG_VAL("T", double, paras);
// 	dt_ = __ARG_VAL("dt", double, paras);
// 	for(double t = t_; t<T; t=t+dt_ )
// 	{
		
// 	}
// }