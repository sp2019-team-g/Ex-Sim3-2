#include "P32.h"

P32::P32(
        double r,
        double rho,
        double kappa,
        double theta,
        double epsilon,
        double T
        ): Process(0.0,T)
{
    r_ = r;
    rho_ = rho;
    kappa_ = kappa;
    theta_ = theta;
    epsilon_ = epsilon;
    loaded_ = false;
    post_update();
}

void P32::post_update()
{
/*
 * TODO: Validate Inputs
 * */
    eps2_ = epsilon*epsilon; 
    p_ = - (2.0*kappa_*theta_)/eps2_;
    v_ = p_ * (kappa_+eps2_)/(kappa_*theta_) - 1.0;
    Delta_ = T_*eps2_/4.0; 
    delta_ = 4.0*(eps2_+kappa_)/eps2_;
    ektT1_ = std::exp((kappa_*theta_*T_)-1.0);
    zp_ = eps2_*etkT1_/(4.0*kappa_*theta_ * (ektT1_/M_E));
    if(loaded_){
        X0_ = 1.0/V0_;
        lambda_ = (X0_*4.0*kappa_*theta_)/(eps2_*ektT1_);

    }

}

void P32::para_load(double S0,double V0){
    S0_ = S0;
    V0_ = V0;
    loaded_ = true;
    post_update();
}

void P32::simulate()
{
    /*Assert loaded
     * */
    double Z = UF::ncChi2Rnd(delta_,lambda_);
    double XT = Z*zp_;
    double x = p_*std::sqrt(XT*X0_);
    std::function<double(double)> Phi = UF::Phi(v_,epslion_,x);
    double mu = UF::numericalDiff(Phi,0,0.01);
    double sigma2 = UF::numericalDiff2(Phi,0,0.01)+nu*nu;
    double sigma = std::sqrt(sigma2);
    double ueps = mu + 12.0*sigma;
    double h = 3*M_PI/(2.0*ueps);
    int N = 0;
    while((std::abs(Phi(N*h))/N) > ((M_PI*epsilon_)/2.0))
        N+=1;
    std::function<double(double)> F = [&,h,N,Phi](double x)->double{
        double res = h*x/2.0;
        for(double i = 1;i<=(double)N;i=i+1){
            res += std::sin(h*i*x)/i*Phi(h*i) * 2/M_PI;
        }
        return res;
    };

    double L = UF::rvs(F,UF::uniRnd(0,1));
    double K = 1/epsilon_ *(std::ln(X0_/XT) + (kappa_+eps2_/2)*L - T*kappa_*theta_);
    double m = std::ln(S_0) + r_*T_-L/2+rho_*K;
    double s = (1-rho_*rho_)*K;
    double ZZ = UF::normalRnd(m,s);
    return std::exp(ZZ);
}

