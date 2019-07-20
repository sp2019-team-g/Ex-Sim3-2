#include "P32.h"

P32::P32(
        double r,
        double rho,
        double kappa,
        double theta,
        double epsilon,
        double dt
        ): Process(dt)
{
    r_ = r;
    rho_ = rho;
    kappa_ = kappa;
    theta_ = theta;
    epsilon_ = epsilon;
    set_loaded(false);
    post_update();
}

P32::P32(Arguments paras):Process(paras)
{
    // Process(0.0, __ARG_VAL("T", double, paras));
    r_ = __ARG_VAL("r", double, paras);
    rho_ = __ARG_VAL("rho", double, paras);
    kappa_ = __ARG_VAL("kappa", double, paras);
    theta_ = __ARG_VAL("theta", double, paras);
    epsilon_ = __ARG_VAL("epsilon", double, paras);
    try{
        S0_ = __ARG_VAL("S0", double, paras);
        V0_ = __ARG_VAL("V0", double, paras);
        set_loaded(true);
    }catch(...){
        set_loaded(false);
    }
    post_update();
}

void P32::post_update()
{
/*
 * TODO: Validate Inputs
 * */
    double T = get_dt();
    eps2_ = epsilon_*epsilon_;
    p_ = - (2.0*kappa_*theta_)/eps2_;
    v_ = p_ * (kappa_+eps2_)/(kappa_*theta_) - 1.0;
    Delta_ = T*eps2_/4.0; 
    delta_ = 4.0*(eps2_+kappa_)/eps2_;
    ektT1_ = std::exp((kappa_*theta_*T)-1.0);
    zp_ = eps2_*ektT1_/(4.0*kappa_*theta_ * (ektT1_/M_E));
    if(check_loaded()){
        X0_ = 1.0/V0_;
        lambda_ = (X0_*4.0*kappa_*theta_)/(eps2_*ektT1_);

    }

}

void P32::para_load(Arguments paras){
    S0_ = __ARG_VAL("S0", double, paras);
    V0_ = __ARG_VAL("V0", double, paras);
    set_loaded(true);
    post_update();
}

double P32::simulate()
{
    double T = get_T();
    double Z = UF::ncChi2Rnd(delta_,lambda_);
    double XT = Z*zp_;
    double x = p_*std::sqrt(XT*X0_);
    std::function<double(double)> Phi = UF::Phi(v_,epsilon_,x);
    double mu = UF::numericalDiff(Phi,0,0.01);
    double sigma2 = UF::numericalDiff2(Phi,0,0.01)+mu*mu;
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
    double K = 1/epsilon_ *(std::log(X0_/XT) + (kappa_+eps2_/2)*L - T*kappa_*theta_);
    double m = std::log(S0_) + r_*T-L/2+rho_*K;
    double s = (1-rho_*rho_)*K;
    double ZZ = UF::normalRnd(m,s);
    return std::exp(ZZ);
}

double P32::simulate(Arguments paras)
{
    /*Assert loaded
     * */

    double* ST = new double(simulate());
    __ARG_SET("ST",ST,paras);
    return *ST;
}

