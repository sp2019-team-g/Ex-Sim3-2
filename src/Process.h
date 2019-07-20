#ifndef PSS_EX32_H
#define PSS_EX32_H

#include "Util.h"
#include "Arguments.h"
class Process
{
    public:
        Process(double);
        Process(Arguments);
        void set_loaded(bool);
        double get_dt();
        bool check_loaded();
        virtual double simulate(){return -1.0;}
        virtual double simulate(Arguments){return -1.0;};
        virtual double closeForm(Arguments){return -1.0;};
        virtual void para_load(Arguments){};

    private:
        double dt_;
        bool loaded_;

};


#endif

