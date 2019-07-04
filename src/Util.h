#ifndef UTIL_EX32_H
#define UTIL_EX32_H


#include <boost/math/special_functions/bessel.hpp>
#include <boost/math/distributions/non_central_chi_squared.hpp>
#include <boost/math/distributions/normal.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/variate_generator.hpp>


#include<random>
#include<cmath>
#include<ctime>
#include<functional>
#include<iostream>

namespace UtilFunc{
    double numericalDiff(std::function<double(double)>, double, double);
    double numericalDiff2(std::function<double(double)>, double, double);
    std::function<double(double)> Phi(double, double, double);
    double sum(std::function<double(int)>, int, int);
    double normalRnd(double, double);
    double ncChi2Rnd(double, double);
    double uniRnd(double , double);
    double rvs(std::function<double(double)>,double);
}
namespace UF = UtilFunc;


#endif

