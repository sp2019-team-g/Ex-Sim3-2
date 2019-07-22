#include "Factory.h"
#include "EUCallOpt.h"
#include "EUPutOpt.h"
#include "P32.h"
#include "McPricingEng.h"

#include <iostream>
using namespace std;
int main(){
	Factory<P32, McPricingEng, EUCallOpt> fac = Factory<P32, McPricingEng, EUCallOpt>();
	fac.build();
	cout<<fac.price()<<endl;
	return 0;
}