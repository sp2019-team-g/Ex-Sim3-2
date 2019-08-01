#include "BES.h"

#include <complex>
#include <iostream>
using namespace std;

int main()
{
	cout<<BES::I(complex<double>(121.99,21.12),120.0)<<endl;
    cout<<BES::I(complex<double>(0.331,0.68),1.22)<<endl;
	return 0.0;
}
