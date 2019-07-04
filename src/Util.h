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
    double numericalDiff(std::function<double(double)>f, double x, double dx);
    double numericalDiff2(std::function<double(double)>f, double x, double dx);
    std::function<double(double)> Phi(double nu, double epsilon, double x);
    double sum(std::function<double(int)> f, int begin, int end);
    double normalRnd(double mean, double std);
    double ncChi2Rnd(double delta, double lambda);
}
namespace UF = UtilFunc;


#endif

