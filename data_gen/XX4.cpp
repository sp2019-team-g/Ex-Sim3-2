#include "Factory.h"
#include "EUOption.h"
#include "BOption.h"
#include "ASOption.h"

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

    string obv = "rho";
    string type = "PUT";
    string optype = "AS";
    string oth = "ARI";
    string othh = "STRIKE";
    string othhh = "0.4dt7.2T";


    Factory<P32, McPricingEng, ASOption> fac = Factory<P32, McPricingEng, ASOption>();
    fac.SET<string>("csv_name", new string("data/" + optype + type + obv + oth + othh + othhh + ".csv"));
    fac.SET<vector<string> >("csv_title", new vector<string>
        ({
            "simulations", "time_usage", "result", "std_err", obv
        })
    );
    fac.SET<CSVLogger>("csv", new CSVLogger(fac.get_arg()));
    fac.SET<string>("obv", new string(obv));

    fac.SET<string>("CP", new string(type));
    fac.SET<string>("AG", new string(oth));
    fac.SET<string>("FF", new string(othh));


    fac.SET<double>("r", new double(0.05));
    fac.SET<double>("rho", new double(-0.5));
    fac.SET<double>("kappa", new double(2.0));
    fac.SET<double>("theta", new double(1.5));
    fac.SET<double>("epsilon", new double(0.2));
    fac.SET<double>("dt", new double(0.8));
    fac.SET<double>("S0", new double(1.0));
    fac.SET<double>("V0", new double(1.125));
    fac.SET<size_t>("nos", new size_t(2560));
    fac.SET<double>("T", new double(7.2));
    fac.SET<double>("K", new double(1.0));
    fac.SET<bool>("verbose", new bool(true));


    for(double x = -1.0; x <= 1.0; x += 0.05)
    {
        fac.SET<double>(obv, new double(x));
        fac.build();
        fac.price();
        cout << optype + type + obv + oth << x << endl;
    }

    
    return 0;
}