#include "Arguments.h"
#include <iostream>
using namespace std;
class PTRTEST{
	public:
		PTRTEST(int a):a(a){}
		int a;
};
int main(){
	int*a = new int(3);
	Arguments arg = Arguments();
	// arg.set("a",(void*)a);
	// cout<<"__ARG_SET(\"a\",a,arg)" <<endl;
	__ARG_SET("a",a,arg);
	PTRTEST* ca = new PTRTEST(34);
	__ARG_SET("ca",ca,arg);
	// // arg.set("ca",(void*)ca);
	cout<<__ARG_PTR("ca",PTRTEST,arg)->a<<endl;
	cout<<__ARG_VAL("a",int,arg)<<endl;
	return 0;
}
