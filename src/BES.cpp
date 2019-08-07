#define _USE_MATH_DEFINES
#include "BES.h"
#include <cmath>
// spouge approximation

namespace
{
    std::complex<double> gamma(std::complex<double>x)
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
        return es * (std::sqrt(2.0 * M_PI) + pp);
    }

    std::complex<double> hyper0F1(std::complex<double>a, double z)
    {
        std::complex<double> res = std::complex<double>(0.0, 0.0);
        double tol = 1e-8;
        std::complex<double> pp = tol + std::complex<double>(1.0, 0.0);
        double k = 0.0;
        std::complex<double> ga = gamma(a);
        while(std::abs(pp) > tol)
        {
            // pp = (std::pow(z, k) * gamma(a)) / (gamma(a + k) * std::tgamma(k + 1.0));
            pp = (std::pow(z, k) * ga) / (gamma(a + k) * std::tgamma(k + 1.0));
            res += pp;
            k += 1.0;
        }
        return res;
    }


}

std::complex<double> BES::I(std::complex<double> v, double x)
{
    return pow(0.5 * x, v) / gamma(v + 1.0) * hyper0F1(v + 1.0, 0.25 * x * x);
}

double BES::CR_PHI(
    double v,
    double eps, 
    double kappa, 
    double theta, 
    double T,
    double coeff
    )
{
    return coeff * M_PI * v * eps / (std::sqrt(kappa), std::exp(theta), T * T);
}
