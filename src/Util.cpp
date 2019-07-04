#include"Util.h"


std::random_device rd;
std::default_random_engine re;
std::uniform_real_distribution<double> U(0.0,1.0);

double UF::numericalDiff(
        std::function<double(double)>f,
        double x,
        double dx
        )
{
    return (f(x+dx)-f(x-dx))/(2.0*dx);
}

double UF::numericalDiff2(
        std::function<double(double)>f,
        double x,
        double dx
        )
{
    return (f(x-dx)-2.0*f(x)+f(x+dx))/(dx*dx);
}

std::function<double(double)> UF::Phi(double nu, double epsilon, double x)
{
    return [&,nu,epsilon,x](double a) mutable -> double
    {
        return boost::math::cyl_bessel_i(nu-(8*x)/(epsilon*epsilon),x)/boost::math::cyl_bessel_i(nu,x);
    };
}

double UF::sum(std::function<double(int)> f, int begin, int end)
{
    double sum = 0;
    for(int i = begin; i != end; i++)
        sum += f(i);
    return sum;
}

double UF::normalRnd(double mean, double std)
{
    re.seed(rd());
    double p = U(re);
    auto dist = boost::math::normal_distribution<double>(mean,std);
    return boost::math::quantile(dist,p);
}

double UF::ncChi2Rnd(double delta, double lambda)
{   
    re.seed(rd());
    double p = U(re);
    
    auto dist = boost::math::non_central_chi_squared_distribution<double>(delta,lambda);
    return boost::math::quantile(dist,p);
}





