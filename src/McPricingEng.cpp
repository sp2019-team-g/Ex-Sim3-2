
#include "Process.h"
#include "Option.h"
#include "McPricingEng.h"
#include "Exceptions.h"


#include <cmath>
#include <functional>
#include <vector>
#include <ctime>

#include <stdio.h>

#include <iostream>
#include <fstream>
McPricingEng::McPricingEng(Option*opt, Process*pro) : PricingEng(opt){pro_ = pro;}

McPricingEng::McPricingEng(Arguments& paras) : PricingEng(paras)
{
    pro_ = paras.g_PTR<Process>("process");
}

double McPricingEng::price()
{
    throw BadAccess_Exception();
}

double McPricingEng::price(Arguments& paras)
{
    clock_t t0 = std::clock();
    size_t bsize = paras.g_VAL<size_t>("nos");
    double T = paras.g_VAL<double>("T");
    double r = paras.g_VAL<double>("r");
    double res = 0.0;
    bool verbose = false;
    double var2 = 0.0;
    double poff = 0.0;
    bool dbg = false;
    std::ofstream* dbgofs = nullptr;
    if(paras.has("verbose"))
        verbose = paras.g_VAL<bool>("verbose");

    if(verbose)
    {
        std::cout << "simulating..." << std::endl;
        printf("------");
        std::cout<<std::flush;
    }
    if(paras.has("dbg"))
    {
        dbg = true;
        dbgofs = paras.g_PTR<std::ofstream>("dbg");
        (*dbgofs) << "[";
    }
    for(size_t i = 0; i < bsize; i++)
    {
        if(verbose && (!(i%50)))
        {
            printf("\b\b\b\b\b\b");
            printf("%05.2f%%", (double)i / (double)bsize * 100.0);
            std::cout << std::flush;
        }

        pro_ -> simulate(paras);
        poff = opt_ -> payoff(paras);
        if(i > 1)
            var2 = (
                ((double)i - 1.0) / ((double)i) * var2 
                +
                (poff - res / (double)(i)) * (poff - res / (double)(i)) / (double)(i + 1)
            );
        res += poff;
        if(dbg)
            (*dbgofs) << poff << ",";
    }
    if(dbg)
        (*dbgofs) << "]" << std::endl << std::endl;
    res = res * std::exp(-r * T) / (double) (bsize);
    clock_t dt = std::clock() - t0;
    if(verbose)
    {
        printf("\b\b\b\b\b\b");
        std::cout << "100%--" << std::endl;
        std::cout << "done." << std::endl;
        std::cout << "result: " << res << std::endl;
        std::cout << "std err: " << std::sqrt(var2) * std::exp(-r * T) / std::sqrt(bsize) << std::endl;
        std::cout << "time usage: " << (double)dt / CLOCKS_PER_SEC << std::endl;
        std::cout << "avg sims per sec: " << (double)bsize * CLOCKS_PER_SEC / (double)dt;
        std::cout << std::endl;
        std::cout << std::endl;
    }

    return res;
}
