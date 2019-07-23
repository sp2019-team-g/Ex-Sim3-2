#include "Factory.h"
#include "PGBM.h"
#include "EUCallOpt.h"
#include "McPricingEng.h"

#include <iostream>

using namespace std;

int main()
{
	Factory<PGBM, McPricingEng, EUCallOpt> fac = Factory<PGBM, McPricingEng, EUCallOpt>();
	fac.build();
	Arguments& a = fac.get_arg();
	cout<<fac.get_pe() -> price(a)<<endl;
	cout<<fac.price()<<endl;
	return 0;
}
