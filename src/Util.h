#ifndef UTIL_EX32_H
#define UTIL_EX32_H

#define _USE_MATH_DEFINES
#include <cmath>
#include <functional>
#include <complex>
#include <limits>

namespace UtilFunc
{
    const double INF = std::numeric_limits<double>::infinity();
    const double MAXD = 1e8;
    std::complex<double> I(std::complex<double>, std::complex<double>);
    std::complex<double> I(std::complex<double>, double);
    double Diff(std::function<double(double)>, double, double);
    std::complex<double> numericalDiff(std::function<std::complex<double>(double)>, double, double);
    std::complex<double> numericalDiff2(std::function<std::complex<double>(double)>, double, double);
    double normalRnd(double, double);
    double ncChi2Rnd(double, double);
    double uniRnd(double, double);
    double rvs(std::function<double(double)>, double, double, double, double, double);
    double rvs(std::function<double(double)>, double, double, double, double);
    double rvs(std::function<double(double)>, double);
    inline double sgn(double x)
    {
        if(x > 0.0) return 1;
        else if(x == 0.0) return 0.0;
        return -1;
    }

    inline double max(double a, double b)
    {
        if(a>b) return a;
        return b;
    }

    inline double asmax(double x, double tol)
    {
        if(std::abs(x) > tol) return x;
        return sgn(x)*tol;
    }
}
namespace UF = UtilFunc;
// std::complex<double> operator/(std::complex<double>, double);

#endif

