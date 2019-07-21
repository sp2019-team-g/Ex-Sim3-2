#include "Option.h"

using namespace std;
int main()
{
	Arguments arg = Arguments();

	double*K = new double(3.41);
	double*T = new double(1.13);
	double*ST = new double(1.44);
	__ARG_SET((string)"K",K,arg);
	__ARG_SET((string)"T",T,arg);
	__ARG_SET((string)"ST",ST,arg);


	function<double(Arguments)>*f = new function<double(Arguments)>(
		[](Arguments a)->double{
			return __ARG_VAL("K",double,a) - __ARG_VAL("ST",double,a);
		}
	);
	// delete f;
	__ARG_SET("payoff",f,arg);
	// cout<<f->operator()(arg)<<endl;
	Option opt = Option(arg);
	cout<<opt.payoff(arg)<<endl;
	return 0;
}

