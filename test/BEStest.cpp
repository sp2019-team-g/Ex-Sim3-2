#include "BES.h"

#include <complex>
#include <iostream>
using namespace std;

int main()
{
	cout<<BES::I(complex<double>(121.99,21.12), 120.0)<<endl;
    cout<<BES::I(complex<double>(0.331,0.68), 1.22)<<endl;


    cout<<"=============="<<endl;
    cout<<BES::gammaP(complex<double>(125.552, 0.224), 60.0)<<endl;
	return 0.0;
}
