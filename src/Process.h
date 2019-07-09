#ifndef PSS_EX32_H
#define PSS_EX32_H

#include "Util.h"
#include "Arguments.h"
class Process
{
    public:
        Process(double, double);
        Process(Arguments);
        virtual ~Process(){};
        void set_t(double);
        void set_T(double);
        void set_loaded(bool);
        double get_t();
        double get_T();
        double get_dt();
        bool check_loaded();
        virtual double simulate(Arguments){return -1.0;};
        virtual double closeForm(Arguments){return -1.0;};
        virtual void para_load(Arguments){};

    private:
        double t_;
        double T_;
        double dt_;
        bool loaded_;

};


#endif

