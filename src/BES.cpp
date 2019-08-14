//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  BES.cpp
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
#define _USE_MATH_DEFINES
#include "BES.h"
#include "Exceptions.h"
#include <cmath>
#include <iostream>
#include <cassert>
const std::complex<double> CP0(0.0, 0.0);
namespace
{
    //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
    //  gamma
    //      calculate gamma(x) with spouge's approximation
    //      accurate, but slow, only used when the fast method overflow
    //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
    std::complex<double> gammax(std::complex<double> x)
    {
        double a = 11.0; 
        std::complex<double> es = std::pow(x - 1.0 + a, x - 0.5) * std::exp(-x + 1.0 - a);   
        std::complex<double> pp = std::complex<double>(0.0, 0.0);    

         std::complex<double> tem = std::complex<double>(0.0, 0.0);  
        for(double i = 1; i < a - 1.0; i++)  
        {    
            tem = std::pow(-1.0, i - 1.0) / std::tgamma(i);  
            pp += tem * std::pow(a - i, i - 0.5) * std::exp(a - i) / (x - 1.0 + i);    
        }    
        std::complex<double>res = es * (std::sqrt(2.0 * M_PI) + pp); 

         return res;
    }
    //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
    //  gamma
    //      calculate gamma(x)
    //      not very accurate, but very fast
    //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
    std::complex<double> gamma(std::complex<double> x)
    {
        std::complex<double> res = 
        (
            std::sqrt(2.0 * M_PI / x) * 
            std::pow
            (
                x / M_E * std::sqrt
                (
                    x * std::sinh(1.0 / x) + 1.0 / (810.0 * std::pow(x, 6.0))
                ), x
            )
        );
        if((std::real(res) != std::real(res)) || (std::imag(res) != std::imag(res)))
            return gammax(x);
        return res;
    }
    //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
    //  gammaP
    //      calculate gamma(z)/gamma(z + k)
    //      not very accurate
    //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
    std::complex<double> gammaP(std::complex<double>z, double k)
    {
        std::complex<double> rz = 1.0 / z;
        std::complex<double> p1 = std::sqrt((z + k) * rz);
        std::complex<double> p2 = std::exp(k);
        std::complex<double> p3 = std::pow((z + k) * rz, -z - k) * std::pow(z, -k);
        double p4 = std::pow(9.0, k) * std::pow(10.0, 0.5 * k);
        std::complex<double> p5 = std::pow(810.0 * z * std::sinh(rz) + 1.0, 0.5 * z);
        std::complex<double> p6 = 1.0/std::pow(k + z, 6.0);
        std::complex<double> p7 = (
            810.0 * std::pow(k, 7.0) +
            5670.0 * std::pow(k, 6.0) * z +
            17010.0 * std::pow(k, 5.0) * std::pow(z, 2.0) +
            28350.0 * std::pow(k, 4.0) * std::pow(z, 3.0) + 
            28350.0 * std::pow(k, 3.0) * std::pow(z, 4.0) +
            17010.0 * std::pow(k, 2.0) * std::pow(z, 5.0) +
            5670.0 * k * std::pow(z, 6.0) + 
            810.0 * std::pow(z, 7.0)
        );
        
        std::complex<double> p8 = std::sinh(1.0 / (z + k));
        std::complex<double> pdim = p6 * (p7 * p8 + 1.0);
        std::complex<double> pdet = std::pow(pdim, -0.5 * k);
        std::complex<double> pdfe = std::pow(pdim, -0.5 * z);

        std::complex<double> res =  p1 * p2 * p3 * p4 * p5 * pdfe * pdet;
        return res;
    }
    //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
    //  mag
    //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
    int mag(double z)
    {
        try
        {
            return (int)std::log10(z);
        }
        catch(...)
        {
            return -400;
        }
    }
    //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
    //  mag
    //      estimate the magnitude of a number
    //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
    int mag(std::complex<double> z)
    {
        int magr = mag(std::real(z));
        int magi = mag(std::imag(z));
        if(abs(magr) > abs(magi))
            return magr;
        return magi;
    }
    //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
    //  cpowmul
    //      handel m * z^k where abs(m*z^k) < 1e300 but abs(z^k) is likely to be
    //          greater than 1e300 
    //      magz(int): magnitude of z
    //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
    std::complex<double> cpowmul(
        std::complex<double> z, 
        double k, 
        std::complex<double> m,
        int magz
    )
    {
        if(magz * k < 200)
            return std::pow(z, k) * m;
        return std::pow(cpowmul(z, 0.5 * k, std::sqrt(m), (int)(magz * 0.5)), 2.0);
    }
    //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
    //  hyper0F1
    //      confluent hypergeometric limit functions
    //      https://en.wikipedia.org/wiki/Generalized_hypergeometric_function
    //          #The_series_0F1
    //      ga(complex): gamma(a)
    //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
    std::complex<double> hyper0F1
    (
        std::complex<double> a, 
        double z, 
        std::complex<double> ga
    )
    {
        std::complex<double> res = std::complex<double>(0.0, 0.0);
        double tol = 1e-8;
        std::complex<double> pp = tol + std::complex<double>(1.0, 0.0);
        double k = 0.0;
        while(std::abs(pp) > tol)
        {
            std::complex<double> apk = CP0;
            int magz = mag(z);
            if(magz * k >= 200)
            {
                apk = gammaP(a, k);
                pp = cpowmul(z, k, apk, mag(z)) / std::tgamma(k + 1.0); 
            }
            else
            {
                apk = ga / gamma(a + k);
                pp = (std::pow(z, k) / std::tgamma(k + 1.0)) * apk;
            }

            res += pp;
            k += 1.0;
        }
        return res;
    }
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  BES::I 
//      Modified Bessel function of the first kind
//      v(complex): order
//      x(double): argument 
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
std::complex<double> BES::I(std::complex<double> v, double x)
{
    std::complex<double> ga = gamma(v + 1.0);
    return std::pow(0.5 * x, v) / ga * hyper0F1(v + 1.0, 0.25 * x * x, ga);
}


//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  End
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
