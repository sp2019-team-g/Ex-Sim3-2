#include "Process.h"

Process::Process(double t, double T)
{
    t_ = t;
    T_ = T;
    dt_ = T-t;
}

Process::Process(Arguments paras){
    t_ = __ARG_VAL(std::string("t"), double, paras);
    T_ = __ARG_VAL(std::string("T"), double, paras);
    dt_ = T_ - t_;
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

double Process::get_dt()
{
    return dt_;
}




