

#include "P32.h"
#include "Util.h"
#include "BES.h"

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
    v_ = 2.0 * kappa_*theta_*(kappa_+eps2_)/(eps2_*kappa_*theta_) - 1.0;
    Delta_ = 0.25 * T * eps2_; 
    delta_ = 4.0*(eps2_+kappa_)/eps2_;
    ektT_ = std::exp(kappa_*theta_*T);
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

    double x = p_*std::sqrt(XT*X0_)/std::sinh(p_*Delta_);
    double v = v_;
    double eps2 = eps2_;
    std::function<std::complex<double>(double)> Phi = [&, v, x, eps2](double a) -> std::complex<double>
    {
        return UF::I(std::sqrt(std::complex<double>(v*v, - 8*a/eps2)), x)/UF::I(std::abs(v), x);
    };

    double eps = epsilon_;
    double theta = theta_;
    double kappa = kappa_;
    double ub = BES::CR_PHI(v, eps, kappa, theta, T, 6.0);

    cout << " v , x ["<<v<<" , "<<x<<"]"<<endl;

    std::function<double(double)> F = [&, Phi, eps, theta, kappa](double x)->double
    {
        // cout <<"("<<flush;
        double tb = ub + BES::CR_PHISIN_P(eps, theta, kappa, x);
        double du = 0.01;
        double res = 0.0;
        // cout<<" tb "<<tb<<flush;
        for(double u = du; u < tb; u += du)
        {
            double rpu = real(Phi(u));
            if(rpu != rpu)
                break;
            res += rpu * std::sin(u * x) / u;
            // cout << "-- u x -- "<<u<<" , "<<x<<flush;
            // cout << " res,rpu,sin <"<< res<<" , "<<rpu<< ","<<std::sin(u * x) / u <<">"<<flush;
        }
        res *= 2.0 * du / M_PI;
        return res;
        // cout<<")"<<flush;
    };

    cout <<"["<<flush;
    for(double i = 0.01; i < 30.0; i += 0.25){
        cout << F(i) << ","<<std::flush;
    }
    cout << "]" << endl;
    double L = UF::rvs(F, UF::uniRnd(0.0,1.0), 0.2, 0.0, UF::MAXD);
    double K = 1.0/epsilon_ *(std::log(X0_/XT) + (kappa_+eps2_/2.0)*L - T*kappa_*theta_);

    double m = std::log(S0_) + r_*T-0.5*L+rho_*K;
    double s = (1.0-rho_*rho_)*K;
    double ZZ = UF::normalRnd(m,s);
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

