#include "Factory.h"
#include "EUOption.h"
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

    string obv = "kappa";
    string type = "CALL";
    string optype = "EU";
    string oth = "";


    Factory<P32, McPricingEng, EUOption> fac = Factory<P32, McPricingEng, EUOption>();
    fac.SET<string>("csv_name", new string("data/" + optype + type + obv + oth + ".csv"));
    fac.SET<vector<string> >("csv_title", new vector<string>
        ({
            "simulations", "time_usage", "result", "std_err", obv,
        })
    );
    fac.SET<CSVLogger>("csv", new CSVLogger(fac.get_arg()));
    fac.SET<string>("obv", new string(obv));

    fac.SET<string>("CP", new string(type));
    fac.SET<double>("r", new double(0.05));
    fac.SET<double>("rho", new double(-0.5));
    fac.SET<double>("kappa", new double(2.0));
    fac.SET<double>("theta", new double(1.5));
    fac.SET<double>("epsilon", new double(0.2));
    fac.SET<double>("dt", new double(1.0));
    fac.SET<double>("S0", new double(1.0));
    fac.SET<double>("V0", new double(1.125));
    fac.SET<size_t>("nos", new size_t(2560 * 10));
    fac.SET<double>("T", new double(1.0));
    fac.SET<double>("K", new double(1.0));
    fac.SET<bool>("verbose", new bool(true));


    for(double x = 0.2; x < 2.5; x += 0.1)
    {
        fac.SET<double>(obv, new double(x));
        fac.build();
        fac.price();
        cout << optype + type + obv + oth << x << endl;
    }

    
    return 0;
}