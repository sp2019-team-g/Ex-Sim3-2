#include"Util.h"


std::random_device rd;
std::default_random_engine re;
std::uniform_real_distribution<double> U(0.0,1.0);

std::complex<double> UF::I(std::complex<double> v, std::complex<double> x)
{

    double tol = 1e-8;
    double dt = 1e-4;
    std::complex<double> p1 = std::complex<double>(0.0, 0.0);
    for(double t = 0.0; t < M_PI; t += dt)
        p1 += std::exp(x * std::cos(t))*std::cos(v*t) * dt;
    p1 = p1/M_PI;

    std::complex<double> pp = std::complex<double>(tol + 0.01, 0.0);
    std::complex<double> p2 = std::complex<double>(0.0, 0.0);
    double t = 0.0;
    while(std::abs(pp) > tol){
        pp = std::exp(-x * std::cosh(t) - v*t);
        p2 += pp*dt;
        t += dt;
    }
    p2 = p2 * std::sin(v*M_PI)/M_PI;
    return p1-p2;


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
    // re.seed(rd());
    // double p = U(re);
    // auto dist = boost::math::normal_distribution<double>(mean,std);
    // return boost::math::quantile(dist,p);
    return 0.0;
}

double UF::ncChi2Rnd(double delta, double lambda)
{   
    // re.seed(rd());
    // double p = U(re);
    
    // auto dist = boost::math::non_central_chi_squared_distribution<double>(delta,lambda);
    // return boost::math::quantile(dist,p);
    return 0.0;
}

double UF::uniRnd(double a, double b){
    re.seed(rd());
    return U(re);
}

double UF::rvs(std::function<double(double)> f,double x){
    /*TODO
     * */
    return 0;

}



