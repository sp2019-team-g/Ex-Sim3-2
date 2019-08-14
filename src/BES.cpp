#define _USE_MATH_DEFINES
#include "BES.h"
#include "Exceptions.h"
#include <cmath>
#include <iostream>
#include <cassert>
namespace
{
    std::complex<double> gamma(std::complex<double>x)
    {
        std::complex<double> res = std::sqrt(2.0 * M_PI / x) * std::pow(x / M_E * std::sqrt(x * std::sinh(1.0 / x) + 1.0 / (810.0 * std::pow(x, 6.0))), x);
        if((std::real(res) != std::real(res))||(std::imag(res) != std::imag(res)))
        {
            std::cerr<<"gamma x:" <<x<<std::endl;
            assert(false);
        }
        return res;
    }
    std::complex<double> gammax(std::complex<double>x)
    {
        double a = 11.0; 
        std::complex<double> es = std::pow(x - 1.0 + a, x - 0.5) * std::exp(-x + 1.0 - a);   
        // std::cout << x<<"\t"<<a<<std::endl;  
        // std::cout << std::pow(x - 1.0 + a, x - 0.5)<<"   "<< std::exp(-x + 1.0 - a)<<std::endl;  
        std::complex<double> pp = std::complex<double>(0.0, 0.0);    

         std::complex<double> tem = std::complex<double>(0.0, 0.0);  
        for(double i = 1; i < a - 1.0; i++)  
        {    
            tem = std::pow(-1.0, i - 1.0) / std::tgamma(i);  
            pp += tem * std::pow(a - i, i - 0.5) * std::exp(a - i) / (x - 1.0 + i);  
            // std::cout<<"\t\t\t\t"<<pp<<std::endl;    
        }    
        std::complex<double>res = es * (std::sqrt(2.0 * M_PI) + pp); 

         return res;
    }
    inline int mag(double z)
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
    int mag(std::complex<double> z)
    {
        int magr = mag(std::real(z));
        int magi = mag(std::imag(z));
        assert(magr * magi > 0.0);
        if(abs(magr) > abs(magi))
            return magr;
        return magi;
    }
    std::complex<double> cpowmul(
        std::complex<double> z, 
        double k, 
        std::complex<double> m,
        int magz
    )
    {
        // m*z^k
        if(magz * k < 200)
            return std::pow(z, k) * m;
        return std::pow(cpowmul(z, 0.5 * k, std::sqrt(m), (int)(magz * 0.5)), 2.0);
    }
    std::complex<double> hyper0F1(std::complex<double> a, double z, std::complex<double> ga)
    {
        std::complex<double> res = std::complex<double>(0.0, 0.0);
        double tol = 1e-8;
        std::complex<double> pp = tol + std::complex<double>(1.0, 0.0);
        double k = 0.0;
        while(std::abs(pp) > tol)
        {
            // std::complex<double> gak = gamma(a+k);
            // std::complex<double> apk = ga/gak;
            std::complex<double> apk = BES::gammaP(a, k);
            pp = cpowmul(z, k, apk, mag(z)) / std::tgamma(k + 1.0);
            double tst = std::abs(std::pow(z, k));
            // if(tst != tst)
            //     pp = ((std::pow(z, k) * apk) / std::tgamma(k + 1.0));
            // else
            //     pp = 0.0;
            // std::cout<< k <<"  "<<std::abs(pp)<<std::endl;
            // std::cout<<"\t\t"<< apk << std::endl;
            res += pp;
            // std::cout << pp << "====="<<std::endl;
            k += 1.0;
        }
        // std::cout <<res << "====="<<std::endl;
        
        return res;
    }
}

std::complex<double> BES::I(std::complex<double> v, double x)
{
    std::complex<double> ga = gamma(v + 1.0);
    return std::pow(0.5 * x, v) / ga * hyper0F1(v + 1.0, 0.25 * x * x, ga);
}

std::complex<double> BES::gammaP(std::complex<double>z, double k)
{
    std::complex<double> rz = 1.0/z;
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
    // std::cout<<"--------"<<p1<<" "<<p2<<" "<<p3<<" "<<std::endl;
    // std::cout<<"----------"<<p4<<" "<<p5<<" "<<p6<<" "<<std::endl;
    // std::cout<<"------------"<<p7<<" "<<p8<<" "<<res<<std::endl;
    // std::cout<<"=============="<<pdim<<std::endl;
    // std::cout<<"xxxx"<<res<<std::endl;
    // std::cout<<std::endl<<std::endl;
    return res;
}
