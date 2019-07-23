#ifndef P32_H
#define P32_H

#include "Process.h"
#include "Arguments.h"
#include <vector>
#include <functional>
class P32 : public Process
{
    public:
        P32(double, double, double, double, double, double);
        P32(Arguments&);
        void post_update();
        void para_load(Arguments&);
        double simulate();
        double simulate(Arguments&);
        static PLIST plist()
        {
            PLIST res;
            res.push_back(g_ASK<double>("r"));
            res.push_back(g_ASK<double>("rho"));
            res.push_back(g_ASK<double>("kappa"));
            res.push_back(g_ASK<double>("theta"));
            res.push_back(g_ASK<double>("epsilon"));
            res.push_back(g_ASK<double>("dt"));
            res.push_back(g_ASK<double>("S0"));
            res.push_back(g_ASK<double>("V0"));
            res.push_back(g_ASK<size_t>("N"));
            return res;
        }

    private:
        double r_;
        double rho_;
        double kappa_;
        double theta_;
        double epsilon_;
        double delta_;
        double ektT1_;
        double zp_;
        size_t N_;

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

