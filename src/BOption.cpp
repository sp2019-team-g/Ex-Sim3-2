#include "BOption.h"
#include "Path.h"
#include "Util.h"
#include "Exceptions.h"
#include <cassert>

BOption::BOption(Arguments& paras) : Option(paras)
{
    K_ = paras.g_VAL<double>("K");
    B_ = paras.g_VAL<double>("B");
    cp_ = paras.g_VAL<std::string>("CP");
    ud_ = paras.g_VAL<std::string>("UD");
    io_ = paras.g_VAL<std::string>("IO");
    assert((io_ == "IN") || (io_ == "OUT"));
}

double BOption::payoff(Arguments& paras)
{
    
    Path * pth = paras.g_PTR<Path>("path");
    bool bku = pth -> break_up(B_);
    bool bkd = pth -> break_down(B_);
    double cpd = 0.0;
    if(cp_ == "CALL") cpd = 1.0;
    else if(cp_ == "PUT") cpd = -1.0;
    else throw OPTCPException();
    double ST = paras.g_VAL<double>("ST");
    if(ud_ == "UP")
    {
        if((!bku) && (io_ == "IN")) return 0.0;
        if(bku && (io_ == "OUT")) return 0.0;
    }
    else if(ud_ == "DOWN")
    {
        if((!bkd) && (io_ == "IN")) return 0.0;
        if(bkd && (io_ == "OUT")) return 0.0;
    }
    else throw OPTCPException();
    return UF::max(cpd * (ST - K_), 0.0);
}

