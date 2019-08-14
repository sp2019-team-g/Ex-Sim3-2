#define _USE_MATH_DEFINES
#include "BES.h"
#include "Exceptions.h"
#include <cmath>
// spouge approximation
#include <iostream>
namespace
{
    std::complex<double> gamma(std::complex<double>x)
    {
        double a = 11.0;
        std::complex<double> es = std::pow(x - 1.0 + a, x - 0.5) * std::exp(-x + 1.0 - a);
        std::cout << x<<"\t"<<a<<std::endl;
        std::cout << std::pow(x - 1.0 + a, x - 0.5)<<"   "<< std::exp(-x + 1.0 - a)<<std::endl;
        std::complex<double> pp = std::complex<double>(0.0, 0.0);

        std::complex<double> tem = std::complex<double>(0.0, 0.0);
        for(double i = 1; i < a - 1.0; i++)
        {
            tem = std::pow(-1.0, i - 1.0) / std::tgamma(i);
            pp += tem * std::pow(a - i, i - 0.5) * std::exp(a - i) / (x - 1.0 + i);
            std::cout<<"\t\t\t\t"<<pp<<std::endl;
        }
        std::complex<double>res = es * (std::sqrt(2.0 * M_PI) + pp);
        
        return res;
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
            std::cout<<"\t\t"<<apk<<"   "<<ga<<"   "<<gak<<std::endl;
            std::cout<<k<<"+++"<<std::abs(pp) <<std::endl;
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
    std::cout << " v " << v << std::endl;
    std::cout << " x " << x << std::endl;
    std::cout << " ga " << ga << std::endl;
    std::cout << " (0.5x)^v " << std::pow(0.5*x,v)<<std::endl;
    std::cout << " 0f1 " << hyper0F1(v + 1.0, 0.25 * x * x, ga) <<std::endl;
    return std::pow(0.5 * x, v) / ga * hyper0F1(v + 1.0, 0.25 * x * x, ga);
}

