#include "Arguments.h"
#include <iostream>
using namespace std;
int main(){
	int*a = new int(3);
	Arguments arg = Arguments();
	arg.set("a",(void*)a);
	// cout<<*((int*)(arg.get("a")))<<endl;
	// cout<<__TYC(int)_GD(arg,a)
	cout<<__ARG_VAL("a",int,arg)<<endl;
	return 0;
}
