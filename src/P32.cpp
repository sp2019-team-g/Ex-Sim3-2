

#include "P32.h"
#include "Util.h"
#include "Exceptions.h"


#include <cmath>
#include <cassert>




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
    S0_ = -1.0;
    V0_ = -1.0;
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
    eps2_ = epsilon_ * epsilon_;
    p_ = - (2.0 * kappa_ * theta_) / eps2_;
    v_ = 2.0 * kappa_ * theta_ * (kappa_ + eps2_) / (eps2_ * kappa_ * theta_) - 1.0;
    Delta_ = 0.25 * T * eps2_; 
    delta_ = 4.0 * (eps2_ + kappa_) / eps2_;
    ektT_ = std::exp(kappa_ * theta_ * T);
    zp_ = eps2_ * (ektT_-1.0) / (4.0 * kappa_ * theta_);
    if(check_loaded())
    {
        X0_ = 1.0 / V0_;
        lambda_ = X0_ / zp_;
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
    if((S0_ < 0.0) || (V0_ < 0.0))
        throw PRONotLoaded_Exception();
    double T = get_dt();
    double Z;
    size_t err_count = 0;
    while(err_count < 100)
    {
        try
        {
            Z = UF::ncChi2Rnd(delta_, lambda_);
            break;
        }
        catch(NC_Exception& e)
        {
            if(err_count >= 100)
                throw NCDead_Exception(delta_, lambda_);
        }
        err_count += 1;
    }
    
    double XT = Z * zp_/ektT_;
    double x = p_ * std::sqrt(XT * X0_)/std::sinh(p_ * Delta_);
    double v = v_;
    double eps2 = eps2_;
    std::function<std::complex<double>(double)> Phi = [&, v, x, eps2](double a) -> std::complex<double>
    {
        return UF::I(std::sqrt(std::complex<double>(v * v, - 8.0 * a / eps2)), x) / UF::I(std::abs(v), x);
    };
    double mu = std::real(std::complex<double>(0.0, -1.0) * UF::numericalDiff(Phi, 0.0, 0.01));
    double sigma2 = std::real(-UF::numericalDiff2(Phi, 0.0, 0.01)) - mu * mu;


    double sigma = std::sqrt(sigma2);
    double ueps = mu + 12.0*sigma;
    double h = M_PI/ueps;

    std::function<double(double)> F = [&, h, Phi](double x)->double
    {
        double res = h*x/M_PI;
        double i = 1.0;
        double res2 = 0.0;
        while(std::abs(Phi(h * i)) / i > M_PI * epsilon_ / 2.0 )
        {
            res2 += std::sin(h * i * x) / i * std::real(Phi(h * i));
            i += 1.0;
        }
        return res + res2 * 2.0 / M_PI;
    };
    // double M = 200.0;
    // double w = 0.01;
    // std::vector<double>Xs;
    // std::vector<double>FXs;
    // for(double i = 1.0; i <= M; i += 1.0)
    //     Xs.push_back(w * mu + (i - 1) * (ueps - w * mu) / M);
    // for(
    //     std::vector<double>::iterator it = Xs.begin();
    //     it != Xs.end();
    //     it++
    //     )
    // {
    //     double z = F(*it);
    //     FXs.push_back(z);
    // }


    double L = UF::rvs(F, UF::uniRnd(0.0, 1.0), 0.2, 0.0, UF::MAXD, mu);
    double K = 1.0 / epsilon_ * (std::log(X0_ / XT) + (kappa_ + 0.5 * eps2_) * L - T * kappa_ * theta_);

    double m = std::log(S0_) + r_ * T - 0.5 * L + rho_ * K;
    double s = (1.0 - rho_ * rho_) * L;
    double ZZ = UF::normalRnd(m, s);
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

