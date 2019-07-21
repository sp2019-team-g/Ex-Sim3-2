#include "Arguments.h"
#include <iostream>
#include <string>
using namespace std;
class PTRTEST{
	public:
		PTRTEST(int a):a(a){}
		int a;
};
int main(){
	// int*a = new int(3);
	Arguments arg = Arguments();
	// arg.set("a",(void*)a);
	// cout<<"__ARG_SET(\"a\",a,arg)" <<endl;
	arg.g_SET<int>((string)"a",new int(3));
	// __ARG_SET("a",a,arg);
	// PTRTEST* ca = new PTRTEST(34);
	arg.g_SET<PTRTEST>((string)"ca",new PTRTEST(32));

	// __ARG_SET("ca",ca,arg);
	// // arg.set("ca",(void*)ca);
	cout<<arg.g_PTR<PTRTEST>((string)"ca")->a<<endl;
	// cout<<__ARG_PTR("ca",PTRTEST,arg)->a<<endl;
	cout<<arg.g_VAL<int>((string)"a")<<endl;
	// cout<<__ARG_VAL("a",int,arg)<<endl;
	g_ASK<double>((string)"ST")(arg);
	// __ARG_ASK("ST",double)(arg);
	// cout<<__ARG_VAL("ST",double,arg)<<endl;
	cout<<arg.g_VAL<double>((string)"ST")<<endl;
	// cout<<arg.get((string)"ST")<<endl;



	return 0;
}
