
#include "Util.h"
#include "rv_library.h"
#include "BES.h"


#include <ctime>
#include <random>
#include <cassert>


#include <iostream>
using namespace std;


namespace
{
    std::random_device rd;
    std::default_random_engine re;
    std::uniform_real_distribution<double> U(0.0,1.0);

}

std::complex<double> UF::I(std::complex<double> v, double x){
    return BES::I(v,x);
}

std::complex<double> UF::I(std::complex<double> v, std::complex<double> x)
{

    double tol = 1e-10;
    double dt = 1e-7;
    std::complex<double> p1 = std::complex<double>(0.0, 0.0);
    for(double t = 0.0; t < M_PI; t += dt)
        p1 += std::exp(x * std::cos(t))*std::cos(v*t) * dt;
    p1 = p1/M_PI;

    std::complex<double> pp = std::complex<double>(tol + 0.01, 0.0);
    std::complex<double> p2 = std::complex<double>(0.0, 0.0);
    double t = 0.0;
    while(std::abs(pp) > tol)
    {
        pp = std::exp(-x * std::cosh(t) - v*t);
        p2 += pp*dt;
        t += dt;
    }
    p2 = p2 * std::sin(v * M_PI)/M_PI;
    return p1-p2;

}

double UtilFunc::Diff(std::function<double(double)> f, double x, double dx)
{
    
    return (f(x + dx) - f(x - dx)) / (2.0*dx);
}

std::complex<double> UF::numericalDiff(
        std::function<std::complex<double>(double)>f,
        double x,
        double dx
        )
{
    return (f(x + dx) - f(x - dx))/(2.0*dx);
}

std::complex<double> UF::numericalDiff2(
        std::function<std::complex<double>(double)>f,
        double x,
        double dx
        )
{
    return (f(x - dx) - 2.0*f(x) + f(x + dx))/(dx*dx);
}

double UF::normalRnd(double mean, double std)
{

    re.seed(rd());
    auto dist = std::normal_distribution<double>(mean,std);
    return dist(re);
}

double UF::ncChi2Rnd(double delta, double lambda)
{
    std::function<double(double)> f = [&, delta, lambda](double x)
    {
        return rv::NC_Chi_squ_cdf(x, delta, lambda);
    };
    double a = UF::uniRnd(0.0, 1.0);
    return UF::rvs(f, a, 0.2, 0, UF::MAXD, delta+lambda);
}

double UF::uniRnd(double a, double b)
{
    re.seed(rd());
    return U(re)*(b - a) + a;
}


double numericalDiffDouble(
        std::function<double(double)>f,
        double x,
        double dx
        )
{
    return (f(x + dx) - f(x - dx))/(2.0*dx);
}



//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//XX
//XX    rvs( f, x, eta, b1, b2):  Inverse Transform
//XX
//XX       f (function<double(double)>): a real function
//XX       x (double): a real value to be inverse transformed
//XX       eta (double): learning rate, a positive real number
//XX       b1 (double): lower bound of f's support
//XX       b2 (double): upper bound of f's support
//XX       return (double): a real number z s.t. f(z) = x
//XX
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
double UF::rvs(
    std::function<double(double)> f, 
    double x, 
    double eta, 
    double b1, 
    double b2,
    double inig
    )
{   
    assert(b2 > b1);
    assert(eta > 0);
    double a0 = inig;
    double a1 = inig;
    double delta = 0.0;
    int num = 0;
    do
    {
        a1 = a0 - eta * (f(a0) - x) / UF::asmax(UF::Diff(f, a0, 0.01), 1e-3);
        if(a1 < b1)
            a1 = UF::uniRnd(b1, a0);
        else if(a1 > b2)
            a1 = UF::uniRnd(a0, b2);

        
        delta = a1 - a0;
        a0 = a1;
        num++;
    }
    while (std::abs(delta) > 0.001 && num < 1000000);

    return a0;

}

double UF::rvs(
    std::function<double(double)> f, 
    double x, 
    double eta, 
    double b1, 
    double b2
    )
{  
    return rvs(f, x, eta, b1, b2, UF::uniRnd(b1,b2));
}

double UF::rvs(std::function<double(double)> f, double x)
{
    return UF::rvs(f, x, 1.0, -UF::MAXD, UF::MAXD);
}
