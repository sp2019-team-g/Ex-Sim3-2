#define P__MAIN__
#include "Besseli.h"
using namespace std;
int main()
{
	BSI::PYB();
	cout<<BSI::I(complex<double>(0.31,0.13), complex<double>(0.41,-0.21))<<endl;
	cout<<BSI::I(0.75, complex<double>(0.15,0.33))<<endl;
	cout<<BSI::I(complex<double>(0.38,-0.19), 0.45)<<endl;
	cout<<BSI::I(0.59,0.21)<<endl;
	BSI::PYE();
	return 0;
}
