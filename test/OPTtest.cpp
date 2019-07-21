#include "Option.h"

using namespace std;
int main()
{
	Arguments arg = Arguments();
	arg.g_SET<double>("K",new double(3.2));
	arg.g_SET<double>("T",new double(1.3));
	arg.g_SET<double>("ST",new double(1.33));


	function<double(Arguments&)>*f = new function<double(Arguments&)>(
		[](Arguments&a)->double{
			return a.g_VAL<double>("K") - a.g_VAL<double>("ST");
		}
	);

	arg.g_SET<function<double(Arguments&)> >("payoff",f);

	Option opt = Option(arg);

	cout<<opt.payoff(arg)<<endl;

	return 0;
}

  