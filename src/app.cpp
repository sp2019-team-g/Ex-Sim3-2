#include "Factory.h"
#include "EUOption.h"
#include "ASCallOpt.h"
#include "ASPutOpt.h"
#include "EUBarrierUpOutCallOpt.h"
#include "EUBarrierUpOutPutOpt.h"
#include "P32.h"
#include "McPricingEng.h"

#include <string>
#include <iostream>
#include <fstream>
using namespace std;
int main()
{

    // Factory<P32, McPricingEng, EUOption> fac = Factory<P32, McPricingEng, EUOption>();
    // fac.SET<string>("CP", new string("CALL"));
    // fac.SET<double>("r", new double(0.05));
    // fac.SET<double>("rho", new double(-0.5));
    // fac.SET<double>("kappa", new double(2.0));
    // fac.SET<double>("theta", new double(1.5));
    // fac.SET<double>("epsilon", new double(0.2));
    // fac.SET<double>("dt", new double(1.0));
    // fac.SET<double>("S0", new double(1.0));
    // fac.SET<double>("V0", new double(1.125));
    // fac.SET<size_t>("nos", new size_t(2560));
    // fac.SET<double>("T", new double(1.0));
    // fac.SET<double>("K", new double(1.0));
    // fac.SET<bool>("verbose", new bool(true));

    // ofstream* offs = new ofstream("dbg.log", ofstream::out); 

    // fac.build();
    // cout << "Case : 2560 sims" << endl;
    // fac.price();

    // fac.SET<size_t>("nos", new size_t(10240));
    // fac.build();
    // cout << "Case : 10240 sims" << endl;
    // fac.price();

    // fac.SET<size_t>("nos", new size_t(40960));
    // fac.build();
    // cout<<"Case : 40960 sims"<<endl;
    // fac.price();

    Factory<P32, McPricingEng, EUBarrierUpOutCallOpt> fac = Factory<P32, McPricingEng, EUBarrierUpOutCallOpt>();
    fac.SET<double>("r", new double(0.05));
    fac.SET<double>("rho", new double(-0.5));
    fac.SET<double>("kappa", new double(2.0));
    fac.SET<double>("theta", new double(1.5));
    fac.SET<double>("epsilon", new double(0.2));
    fac.SET<double>("dt", new double(0.4));
    fac.SET<double>("S0", new double(1.0));
    fac.SET<double>("V0", new double(1.125));
    fac.SET<size_t>("nos", new size_t(100));
    fac.SET<double>("T", new double(1.0));
    fac.SET<double>("K", new double(1.0));
    fac.SET<double>("barrier", new double(2.0));
    fac.SET<bool>("verbose", new bool(true));
    ofstream* offs = new ofstream("dbg.log", ofstream::out);

    fac.build();
    cout << "Case : 100 sims" << endl;
    fac.price();



    offs -> close();
	
    return 0;
}


