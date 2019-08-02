
#include "Process.h"
#include "Option.h"
#include "McPricingEng.h"

#include <cmath>
#include <functional>
#include <vector>
#include <stdexcept>

#include <iostream>
using namespace std;

McPricingEng::McPricingEng(Option*opt, Process*pro) : PricingEng(opt)
{
    pro_ = pro;
}

McPricingEng::McPricingEng(Arguments& paras) : PricingEng(paras)
{
    pro_ = paras.g_PTR<Process>("process");
}

double McPricingEng::price()
{
    throw std::runtime_error("error");
}

double McPricingEng::price(Arguments& paras)
{
    size_t bsize = paras.g_VAL<size_t>("batch_size");

    double T = paras.g_VAL<double>("T");

    double res = 0.0;

    cout << endl;
    cout << " T " << T << endl;
    cout << " e-T "<< std::exp(-T) <<endl; 
    for(size_t i = 0; i < bsize; i = i + 1.0)
    {
        pro_ -> simulate(paras);
        cout << " ST " << paras.g_VAL<double>("ST") << endl;
        cout << " poff " << opt_ -> payoff(paras) << endl;
        res += opt_ -> payoff(paras) * std::exp(-T);
    }
    cout << res <<endl;
    cout<<endl;
    return res/(double)bsize;
}
