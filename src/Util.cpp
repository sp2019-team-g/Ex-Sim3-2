#include"Util.h"


std::random_device rd;
std::default_random_engine re;
std::uniform_real_distribution<double> U(0.0,1.0);

std::complex<double> UF::I(std::complex<double> v, std::complex<double> x)
{

    double tol = 1e-8;
    double dt = 1e-4;
	double u_db = 100000;
	
    std::complex<double> p1 = std::complex<double>(0.0, 0.0);
    for(double t = 0.0; t < M_PI; t += dt)
        p1 += std::exp(x * std::cos(t))*std::cos(v*t);


    std::complex<double> pp = std::complex<double>(tol + 0.01, 0.0);
    std::complex<double> p2 = std::complex<double>(0.0, 0.0);
    double t = 0.0;
	
	while(std::abs(pp) > tol && t < u_bd)
{
        pp = std::exp(-x * std::cosh(t) - v*t);
        p2 += pp;
        t += dt;
    }
    p2 *= std::sin(v*M_PI);
    return (p1 - p2)*dt/M_PI;


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
    re.seed(rd());
    
	auto dist = std::chi_squared_distribution<double>(delta);

    return (dist(re)+lambda);

}

double UF::uniRnd(double a, double b)
{
    re.seed(rd());
    return U(re);
}


double numericalDiffDouble(
        std::function<double(double)>f,
        double x,
        double dx
        )
{
    return (f(x + dx) - f(x - dx))/(2.0*dx);
}

double UF::rvs(std::function<double(double)> f,double x)
{


	double a0 = 0.0;
	double a1 = 1.0;
	double delta = 0.0;
	int num = 0;


	while (std::abs(delta) > 0.01 && num < 1000000)
	{
		a1 = a0 - (f(a0) - x) / UF::Diff(f, a0, 0.01);

		delta = a1 - a0;

		a0 = a1;

		num++;
	}

    return a0;

}


