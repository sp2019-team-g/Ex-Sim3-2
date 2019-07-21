#include "Process.h"

Process::Process(double dt)
{
    dt_ = dt;
}

Process::Process(Arguments paras){
    dt_ = __ARG_VAL(std::string("dt"), double, paras);
}

void Process::set_loaded(bool ldd)
{
    loaded_ = ldd;
}

double Process::get_dt()
{
    return dt_;
}

bool Process::check_loaded()
{
    return loaded_;
}


