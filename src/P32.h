#ifndef P32_H
#define P32_H

#include "Process.h"
#include <vector>
class P32:public Process
{
    public:
        P32(double, double, double, double, double, double);
        P32(Arguments);
        ~P32(){};
        void post_update();
        void para_load(Arguments);
        double simulate(Arguments);

    private:
        double r_;
        double rho_;
        double kappa_;
        double theta_;
        double epsilon_;
        double delta_;
        double ektT1_;
        double zp_;

        double S0_;
        double V0_;

        double eps2_;
        double p_;
        double v_;
        double Delta_;
        double lambda_;

        double X0_;

};

#endif

