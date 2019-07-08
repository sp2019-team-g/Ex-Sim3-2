#ifndef PSS_EX32_H
#define PSS_EX32_H

#include "Util.h"

class Process
{
    public:
        Process(double, double);
        virtual ~Process(){};
        void set_t(double);
        void set_T(double);
        double get_t();
        double get_T();
        double get_dt();
        virtual double simulate(){return -1.0;};
        virtual double closeForm(){return -1.0;};

    private:
        double t_;
        double T_;
        double dt_;

};


#endif

