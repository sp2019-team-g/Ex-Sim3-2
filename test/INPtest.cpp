
#include "Arguments.h"
#include "Input.h"
#include "PGBM.h"
#include <iostream>
using namespace std;
int main()
{
	Arguments a = Arguments();
	Input::buildArg<PGBM>(a);
	cout<<a.g_VAL<double>("mu")<<endl;
	cout<<a.g_VAL<double>("sigma")<<endl;
	cout<<a.g_VAL<double>("S0")<<endl;

	return 0;
}
