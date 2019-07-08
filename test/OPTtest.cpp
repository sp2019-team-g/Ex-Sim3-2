#include "Option.h"

using namespace std;
int main()
{
	Arguments arg = Arguments();
	arg.set((string)"K",new double(3.41));
	arg.set((string)"T",new double(1.13));
	arg.set((string)"ST",new double(1.44));
	function<double(Arguments)> f = [](Arguments a)->double{
		return __ARG_VAL("K",double,a) - __ARG_VAL("ST",double,a);
	};
	arg.set("payoff", &f);
	Option opt = Option(arg);
	cout<<opt.payoff(arg)<<endl;
	return 0;
}

