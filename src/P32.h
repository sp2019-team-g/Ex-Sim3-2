//XXXXXXXXXXXXXXXXXXXXXXXXXX
//   P32.h
//XXXXXXXXXXXXXXXXXXXXXXXXXX
#ifndef P32_EX32_H
#define P32_EX32_H
//XXXXXXXXXXXXXXXXXXXXXXXXXX

#include "Process.h"
#include "Arguments.h"

#include <functional>
//XXXXXXXXXXXXXXXXXXXXXXXXXX
// class P32
//      Stochastic Process for 3/2 Model
//      dS_t/S_t = rdt + sqrt(V_t) rho dW{1t} + sqrt(V_t(1-rho^2) dW{2t})
//      dV_t = kappa V_t(theta - V_t)dt + epsilon (V_t)^(3/2)dW{1t}
//XXXXXXXXXXXXXXXXXXXXXXXXXX
class P32 : public Process
{
    public:
        P32(double, double, double, double, double, double);
        P32(Arguments&);

        void para_validate();
        void post_update();
        void para_load(Arguments&);
        //**************************
        // simulate()
        //**************************
        double simulate();
        double simulate(Arguments&);
        //**************************
        // required parameters:
        //      r (double): groth rate
        //      rho (double): correlation between dW{1t} and d{2t}, range is [-1,1]
        //      epsilon (double): volatility in volatility, positive
        //      theta (double): long term average of volatility, non-negative
        //      dt (double): time gap for simulation, non-negative
        //      S0 (double): initial stock price, non-negative
        //      V0 (double): initial volatility, non-negative
        //**************************
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
            return res;
        }

    private:
        double r_;
        double rho_;
        double kappa_;
        double theta_;
        double epsilon_;
        double delta_;
        double ektT_;
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
//XXXXXXXXXXXXXXXXXXXXXXXXXX
//   End
//XXXXXXXXXXXXXXXXXXXXXXXXXX