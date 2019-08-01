

#include "P32.h"
#include "Util.h"

#include <cmath>
#include <cassert>

#include <iostream>
using namespace std;


P32::P32(
        double r,
        double rho,
        double kappa,
        double theta,
        double epsilon,
        double dt
        ) : Process(dt)
{
    r_ = r;
    rho_ = rho;
    kappa_ = kappa;
    theta_ = theta;    
    epsilon_ = epsilon;
    para_validate();
    set_loaded(false);
    post_update();
}

P32::P32(Arguments& paras) : Process(paras)
{
    r_ = paras.g_VAL<double>("r");
    rho_ = paras.g_VAL<double>("rho");
    kappa_ = paras.g_VAL<double>("kappa");
    theta_ = paras.g_VAL<double>("theta");
    epsilon_ = paras.g_VAL<double>("epsilon");
    N_ = paras.g_VAL<size_t>("N");
    para_validate();
    try
    {
        S0_ = paras.g_VAL<double>("S0");
        V0_ = paras.g_VAL<double>("V0");
        set_loaded(true);
    }
    catch(...)
    {
        set_loaded(false);
    }
    post_update();
}

void P32::para_validate()
{
    Process::para_validate();
    assert(r_ >= 0.0);
    assert(rho_ >= -1.0);
    assert(rho_ <= 1.0);
    assert(kappa_ >= 0.0);
    assert(theta_ >= 0.0);
    assert(epsilon_ > 0.0);
}


void P32::post_update()
{

    double T = get_dt();
    eps2_ = epsilon_*epsilon_;
    p_ = - (2.0*kappa_*theta_)/eps2_;
    v_ = p_ * (kappa_+eps2_)/(kappa_*theta_) - 1.0;
    Delta_ = 0.25 * T * eps2_; 
    delta_ = 4.0*(eps2_+kappa_)/eps2_;
    ektT_ = std::exp(kappa_*theta_*T);
    cout << " kappa " <<kappa_<<endl;
    cout << " theta " <<theta_<<endl;
    cout << " T "<<T<<endl;
    zp_ = eps2_*(ektT_-1.0)/(4.0*kappa_*theta_);
    if(check_loaded())
    {
        X0_ = 1.0/V0_;
        lambda_ = X0_/zp_;
    }

}

void P32::para_load(Arguments& paras)
{
    S0_ = paras.g_VAL<double>("S0");
    V0_ = paras.g_VAL<double>("V0");
    set_loaded(true);
    post_update();
}

double P32::simulate()
{
    double T = get_dt();
    double Z = UF::ncChi2Rnd(delta_, lambda_);
    
    double XT = Z*zp_/ektT_;
    cout<<endl;
    cout<<" Z "<<Z<<endl;
    cout<<" delta "<< delta_<<endl;
    cout<<" lambda "<< lambda_ << endl;
    cout<<" XT "<<XT<<endl;
    double x = p_*std::sqrt(XT*X0_)/std::sinh(p_*Delta_);
    double v = v_;
    double eps2 = eps2_;
    std::function<std::complex<double>(double)> Phi = [&, v, x, eps2](double a) -> std::complex<double>
    {
        return UF::I(std::sqrt(std::complex<double>(v*v, - 8*a/eps2)), x)/UF::I(v, x);
    };

    double mu = std::real(std::complex<double>(0.0, -1.0) * UF::numericalDiff(Phi, 0.0, 0.01));
    double sigma2 = std::real(-UF::numericalDiff2(Phi,0.0,0.01)) - mu*mu;


    double sigma = std::sqrt(sigma2);
    double ueps = mu + 12.0*sigma;
    cout <<" mu "<<mu<<endl;
    cout<<" sigma "<< sigma<<endl;
    cout<<" ueps "<<ueps<<endl;
    // double h = 1.5*M_PI/ueps;
    double h = 0.02;
    double N = (double)N_;

    cout <<" h " << h <<endl;

    std::function<double(double)> F = [&, h, N, Phi](double x)->double
    {
        double res = h*x/M_PI;
        for(double i = 1.0; i<=N; i=i+1.0)
            res += std::sin(h*i*x)/i*std::real(Phi(h*i)) * 2.0/M_PI;
        return res;
    };

    cout <<"[";
    for(double i = 0.0; i < 10.0; i += 0.25){
        cout << F(i) << ",";
    }
    cout << "]" << endl;
    double L = UF::rvs(F, UF::uniRnd(0.0,1.0), 0.2, 0.0, UF::MAXD);
    cout << " L "<< L <<endl;
    double K = 1.0/epsilon_ *(std::log(X0_/XT) + (kappa_+eps2_/2.0)*L - T*kappa_*theta_);

    double m = std::log(S0_) + r_*T-0.5*L+rho_*K;
    double s = (1.0-rho_*rho_)*K;
    cout<<" m "<<m<<endl;
    cout<<" s "<<s<<endl;

    double ZZ = UF::normalRnd(m,s);
    cout<<" ZZ "<<(ZZ)<<endl;
    return std::exp(ZZ);
}

double P32::simulate(Arguments& paras)
{
    /*Assert loaded
     * */
    para_load(paras);
    paras.g_SET<double>("ST", new double(simulate()));
    return 0.0;
}

