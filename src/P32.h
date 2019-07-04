#ifndef P32_H
#define P32_H


#include<boost/math/distributions/non_central_chi_squared.hpp>
#include<cmath>

class P32{
    public:
        P32(double r,double rho,double kappa,double theta,double epsilon);
        ~P32();

    private:
        double S_0_;
        double V_0_;
        double X_0_;
        double delta_;
        double lambda_;
        double T_;
        double theta_;
        double r_;
        double rho_;
        double kappa_;
        double epsilon_;

};

#endif

