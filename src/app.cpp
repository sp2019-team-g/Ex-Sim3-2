#include "Factory.h"
#include "EUCallOpt.h"
#include "EUPutOpt.h"
#include "P32.h"
#include "McPricingEng.h"

#include <string>
#include <iostream>
using namespace std;
int main()
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
    fac.SET<size_t>("nos", new size_t(2560));
    fac.SET<double>("T", new double(1.0));
    fac.SET<double>("K", new double(1.0));
    fac.SET<bool>("verbose", new bool(true));
    
    fac.build();
    cout << "Case V0 = 1" << endl;
    fac.price();

    fac.SET<double>("V0", new double(0.75));
    fac.build();
    cout<<"Case V0 = 0.75"<<endl;
    fac.price();

    fac.SET<double>("V0", new double(0.875));
    fac.build();
    cout << "Case V0 = 0.875" << endl;
    fac.price();



    return 0;
}


