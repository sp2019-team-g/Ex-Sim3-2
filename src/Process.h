#ifndef PSS_EX32_H
#define PSS_EX32_H

#include "Exceptions.h"
class Path;
class Arguments;

class Process
{
    public:
        Process(double);
        virtual ~Process(){};
        Process(Arguments&);
        void para_validate();
        void set_loaded(bool);
        void set_dt(double dt){dt_ = dt;}
        double get_dt();
        bool check_loaded();
        virtual double simulate(){throw BadAccess_Exception();}
        virtual double simulate(Arguments&){throw BadAccess_Exception();};
        virtual Path * simulatePath(Arguments&, double, double, double){throw BadAccess_Exception();}
        virtual void para_load(Arguments&){throw BadAccess_Exception();}

    private:
        double dt_;
        bool loaded_;
};


#endif

