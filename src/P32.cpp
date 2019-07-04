#include "P32.h"

P32::P32(
        double r,
        double rho,
        double kappa,
        double theta,
        double epsilon,
        double T
        ): Process(0,T)
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
    p_ = - (2*kappa_*theta_)/eps2_;
    v_ = p_ * (kappa_+eps2_)/(kappa_*theta_) - 1;
    Delta_ = get_T()*eps2_/4; 
    delta_ = 4*(eps2_+kappa_)/eps2_;
    if(loaded_){
        X0_ = 1/V0_;
    }

}

void P32::para_load(double S0,double V0){
    S0_ = S0;
    V0_ = V0;
    post_update();
}
