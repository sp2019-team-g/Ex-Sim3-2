#include "Process.h"

Process::Process(double t, double T)
{
    t_ = t;
    T_ = T;
    dt_ = T-t;
}

void Process::set_t(double t)
{
    t_ = t;
    dt_ = T_-t_;
}

void Process::set_T(double T)
{
    T_ = T;
    dt_ = T_-t_;
}

double Process::get_t()
{
    return t_;
}

double Process::get_T()
{
    return T_;
}

double Process::get::dt()
{
    return dt_;
}




