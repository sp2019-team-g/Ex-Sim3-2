#define _USE_MATH_DEFINES
#include "BES.h"
#include "Exceptions.h"
#include <cmath>
#include <iostream>
namespace
{
    std::complex<double> gamma(std::complex<double>x)
    {
        return std::sqrt(2.0*M_PI/x)*std::pow(x/M_E *std::sqrt(x * std::sinh(1.0/x) + 1.0/(810.0*std::pow(x,6.0))),x);
    }

    std::complex<double> hyper0F1(std::complex<double> a, double z, std::complex<double> ga)
    {
        std::complex<double> res = std::complex<double>(0.0, 0.0);
        double tol = 1e-8;
        std::complex<double> pp = tol + std::complex<double>(1.0, 0.0);
        double k = 0.0;
        while(std::abs(pp) > tol)
        {
            std::complex<double> gak = gamma(a+k);
            std::complex<double> apk = ga/gak;
            pp = (std::pow(z, k)/std::tgamma(k + 1.0)) * apk;
            // std::cout<<"\t\t"<<apk<<"   "<<ga<<"   "<<gak<<std::endl;
            // std::cout<<k<<"+++"<<std::abs(pp) <<std::endl;
            res += pp;
            k += 1.0;
        }
        // std::cout<<std::abs(pp)<<std::endl;
        return res;
    }
}

std::complex<double> BES::I(std::complex<double> v, double x)
{
    std::complex<double> ga = gamma(v + 1.0);
    return std::pow(0.5 * x, v) / ga * hyper0F1(v + 1.0, 0.25 * x * x, ga);
}

