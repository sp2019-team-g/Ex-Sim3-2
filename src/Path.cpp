#include "Path.h"
#include "Arguments.h"
#include "Process.h"
Path::Path(double t, double dt, double T, std::vector<double>& path)
{
    t_ = t;
    dt_ = dt;
    T_ = T;
    path_ = std::vector<double>(path);
}

Path::Path(Arguments& paras)
{
    T_ = paras.g_VAL<double>("T");
    dt_ = paras.g_VAL<double>("dt");
    path_ = std::vector<double>(*paras.g_PTR<std::vector<double> >("path")); 
}


std::ostream& operator<<(std::ostream& os, Path p)
{
    os << "[";
    for(std::vector<double>::iterator it = p.path_.begin(); it != p.path_.end(); it++)
        os << *it << ",";
    return os<<"]";
}
std::ostream& operator<<(std::ostream& os, Path* p){return os<<(*p);}



