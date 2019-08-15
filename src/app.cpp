#include "Factory.h"
#include "EUOption.h"
#include "ASOption.h"
#include "BOption.h"


#include "P32.h"
#include "McPricingEng.h"
#include "CSVLogger.h"


#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main()
{

    Factory<P32, McPricingEng, EUOption> fac = Factory<P32, McPricingEng, EUOption>();
    fac.SET<string>("csv_name",new string("data/benchmark.csv"));

    fac.SET<vector<string> >("csv_title", new vector<string>
        ({
            "simulations", "time_usage", "result", "std_err"
        })
    );
    fac.SET<CSVLogger>("csv", new CSVLogger(fac.get_arg()));
    fac.SET<string>("CP", new string("CALL"));
    fac.SET<double>("r", new double(0.05));
    fac.SET<double>("rho", new double(-0.5));
    fac.SET<double>("kappa", new double(2.0));
    fac.SET<double>("theta", new double(1.5));
    fac.SET<double>("epsilon", new double(0.2));
    fac.SET<double>("dt", new double(1.0));
    fac.SET<double>("S0", new double(1.0));
    fac.SET<double>("V0", new double(1.125));
    fac.SET<size_t>("nos", new size_t(2560));
    fac.SET<double>("T", new double(1.0));
    fac.SET<double>("K", new double(1.0));
    fac.SET<bool>("verbose", new bool(true));

    ofstream* offs = new ofstream("dbg.log", ofstream::out); 

    fac.build();
    cout << "Case : 2560 sims" << endl;
    fac.price();

    fac.SET<size_t>("nos", new size_t(10240));
    fac.build();
    cout << "Case : 10240 sims" << endl;
    fac.price();

    fac.SET<size_t>("nos", new size_t(40960));
    fac.build();
    cout<<"Case : 40960 sims"<<endl;
    fac.price();

    // Factory<P32, McPricingEng, BOption> fac = Factory<P32, McPricingEng, BOption>();

    // fac.SET<double>("r", new double(0.05));
    // fac.SET<double>("rho", new double(-0.5));
    // fac.SET<double>("kappa", new double(2.0));
    // fac.SET<double>("theta", new double(1.5));
    // fac.SET<double>("epsilon", new double(0.2));
    // fac.SET<double>("dt", new double(0.4));
    // fac.SET<double>("S0", new double(1.0));
    // fac.SET<double>("V0", new double(1.125));
    // fac.SET<size_t>("nos", new size_t(1000));
    // fac.SET<double>("T", new double(3.0));
    // fac.SET<double>("K", new double(1.0));
    // fac.SET<double>("B", new double(1.3));
    // fac.SET<string>("CP", new string("CALL"));
    // fac.SET<string>("IO", new string("IN"));
    // fac.SET<string>("UD", new string("UP"));
    // fac.SET<bool>("verbose", new bool(true));
    // ofstream* offs = new ofstream("dbg.log", ofstream::out);

    // fac.build();
    // cout << "Case : 100 sims" << endl;
    // fac.price();



    offs -> close();
	
    return 0;
}


