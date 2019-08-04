#include "Factory.h"
#include "EUCallOpt.h"
#include "EUPutOpt.h"
#include "ASCallOpt.h"
#include "ASPutOpt.h"
#include "EUBarrierUpOutCallOpt.h"
#include "EUBarrierUpOutPutOpt.h"
#include "P32.h"
#include "McPricingEng.h"

#include <string>
#include <iostream>
using namespace std;
int main()
{
	if (1)
	{
		Factory<P32, McPricingEng, EUCallOpt> fac = Factory<P32, McPricingEng, EUCallOpt>();
		fac.SET<double>("r", new double(0.05));
		fac.SET<double>("rho", new double(-0.5));
		fac.SET<double>("kappa", new double(2.0));
		fac.SET<double>("theta", new double(1.5));
		fac.SET<double>("epsilon", new double(0.2));
		fac.SET<double>("dt", new double(1.0));
		fac.SET<double>("S0", new double(1.0));
		fac.SET<double>("V0", new double(1.0));
		fac.SET<size_t>("nos", new size_t(1));
		fac.SET<double>("T", new double(1.0));
		fac.SET<double>("K", new double(1.0));
		fac.SET<bool>("verbose", new bool(true));

		// fac.build();
		// cout << "Case V0 = 1" << endl;
		// fac.price();

		// fac.SET<double>("V0", new double(0.75));
		// fac.build();
		// cout << "Case V0 = 0.75" << endl;
		// fac.price();

		fac.SET<double>("V0", new double(0.875));
		fac.build();
		cout << "Case V0 = 0.875" << endl;
		fac.price();
	}
    
	if (0)
	{
		Factory<P32, McPricingEng, ASCallOpt> fac2 = Factory<P32, McPricingEng, ASCallOpt>();
		fac2.SET<double>("r", new double(0.05));
		fac2.SET<double>("rho", new double(-0.5));
		fac2.SET<double>("kappa", new double(2.0));
		fac2.SET<double>("theta", new double(1.5));
		fac2.SET<double>("epsilon", new double(0.2));
		fac2.SET<double>("dt", new double(0.1));
		fac2.SET<double>("S0", new double(1.0));
		fac2.SET<double>("V0", new double(1.0));
		fac2.SET<size_t>("nos", new size_t(2560));
		fac2.SET<double>("T", new double(1.0));
		fac2.SET<double>("K", new double(1.0));
		fac2.SET<bool>("verbose", new bool(true));

		fac2.SET<double>("V0", new double(1.0));
		fac2.build();
		cout << "Case V0 = 1.0" << endl;
		fac2.price();
	}

	if (1)
	{
		Factory<P32, McPricingEng, EUBarrierUpOutCallOpt> fac3 = Factory<P32, McPricingEng, EUBarrierUpOutCallOpt>();
		fac3.SET<double>("r", new double(0.05));
		fac3.SET<double>("rho", new double(-0.5));
		fac3.SET<double>("kappa", new double(2.0));
		fac3.SET<double>("theta", new double(1.5));
		fac3.SET<double>("epsilon", new double(0.2));
		fac3.SET<double>("dt", new double(0.1));
		fac3.SET<double>("S0", new double(1.0));
		fac3.SET<double>("V0", new double(1.0));
		fac3.SET<size_t>("nos", new size_t(2560));
		fac3.SET<double>("T", new double(1.0));
		fac3.SET<double>("K", new double(1.0));
		fac3.SET<double>("UP", new double(1.1));
		fac3.SET<double>("DOWN", new double(0.9));
		fac3.SET<bool>("verbose", new bool(true));

		fac3.SET<double>("V0", new double(1.0));
		fac3.build();
		cout << "Case V0 = 1.0" << endl;
		fac3.price();
	}
	
    return 0;
}


