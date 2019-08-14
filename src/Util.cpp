
#include "Util.h"
#include "BES.h"
#include "Exceptions.h"


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
    throw BadAccess_Exception();
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
    return (f(x - dx) - 2.0 * f(x) + f(x + dx))/(dx*dx);
}

double UF::normalRnd(double mean, double std)
{

    re.seed(rd());
    auto dist = std::normal_distribution<double>(mean, std);
    return dist(re);
}

double UF::chi2Rnd(double delta)
{
    re.seed(rd());
    std::chi_squared_distribution<double> dist(delta);
    return dist(re);
}

double UF::ncChi2Rnd(double delta, double lambda)
{
    if(delta <= 1.0) throw NC_Exception();
    if(lambda < 0.0) throw NC_Exception();
    double Y = UF::chi2Rnd(delta - 1.0);
    double Z = UF::normalRnd(std::sqrt(lambda), 1.0);
    return Y + Z * Z;
}

double UF::uniRnd(double a, double b)
{
    re.seed(rd());
    return U(re) * (b - a) + a;
}


double numericalDiffDouble(
        std::function<double(double)>f,
        double x,
        double dx
        )
{
    return (f(x + dx) - f(x - dx)) / (2.0 * dx);
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

// std::complex<double> operator/(std::complex<double> z, double x)
// {
//     return std::complex<double>(z.real()/x, z.imag()/x);
// }

