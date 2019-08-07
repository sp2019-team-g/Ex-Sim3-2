#include "Arguments.h"
#include "Path.h"
#include "P32.h"


#include <iostream>

using namespace std;

int main()
{
	Arguments a = Arguments();
    a.g_SET<double>("r", new double(0.0001));
    a.g_SET<double>("rho", new double(0.1));
    a.g_SET<double>("kappa", new double(2.0));
    a.g_SET<double>("theta", new double(1.5));
    a.g_SET<double>("epsilon", new double(0.2));
    a.g_SET<double>("T", new double(20.0));

    a.g_SET<double>("S0", new double(6.0));
    a.g_SET<double>("V0", new double(0.05));

    a.g_SET<double>("dt", new double(1.0));

    Path* pth = P32(a).simulatePath(a);

    cout << pth << endl;


	return 0;
}