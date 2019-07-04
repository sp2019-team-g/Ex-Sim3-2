#ifndef P32_H
#define P32_H

#include "Process.h"

class P32:public Process{
    public:
        P32(double, double, double, double, double, double);
        ~P32(){};
        void post_update();
        void para_load(double, double);
        double simulate();

    private:
        double r_;
        double rho_;
        double kappa_;
        double theta_;
        double epsilon_;

        bool loaded_;

        double S0_;
        double V0_;

        double eps2_;
        double p_;
        double v_;
        double Delta_;
        double delta_;
        double lambda_;

        double X0_;

};

#endif

