#include"Util.h"


std::random_device rd;
std::default_random_engine re;
std::uniform_real_distribution<double> U(0.0,1.0);



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

double UF::uniRnd(double a, double b){
    re.seed(rd());
    return U(re);
}

double UF::rvs(std::function<double(double)>,double){
    /*TODO
     * */
    return 0;

}



