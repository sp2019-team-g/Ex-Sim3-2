
#include "Process.h"
#include "Option.h"
#include "McPricingEng.h"

#include <cmath>
#include <functional>
#include <vector>
#include <stdexcept>
#include <ctime>

#include <stdio.h>

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
    clock_t t0 = std::clock();
    size_t bsize = paras.g_VAL<size_t>("batch_size");
    double T = paras.g_VAL<double>("T");
    double res = 0.0;
    bool verbose = false;

    if(paras.has("verbose"))
        verbose = paras.g_VAL<bool>("verbose");

    if(verbose)
    {
        std::cout << "simulating..." << std::endl;
        printf("------");
        std::cout<<std::flush;
    }

    for(size_t i = 0; i < bsize; i++)
    {
        if(verbose && (!(i%50)))
        {
            printf("\b\b\b\b\b\b");
            printf("%05.2f%%", (double)i / (double)bsize * 100.0);
            cout<<flush;
        }

        pro_ -> simulate(paras);
        res += opt_ -> payoff(paras);
    }
    res = res * std::exp(-T) / (double) bsize;
    clock_t dt = std::clock() - t0;
    if(verbose)
    {
        printf("\b\b\b\b\b\b");
        std::cout << "100%--" << std::endl;
        std::cout << "done." << std::endl;
        std::cout << "result: " << res << std::endl;
        std::cout << "time usage: " << (double)dt / CLOCKS_PER_SEC << std::endl;
        std::cout << "avg sims per sec: " << (double)bsize * CLOCKS_PER_SEC / (double)dt;
        std::cout << std::endl;
        std::cout << std::endl;
    }

    return res;
}
