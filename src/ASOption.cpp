#include "ASOption.h"
#include "Path.h"
#include "Util.h"


ASOption::ASOption(double T, double K, std::string cp, std::string ff, std::string ag) : Option(T)
{
    K_ = K;
    cp_ = cp;
    ff_ = ff;
    ag_ = ag;
}

ASOption::ASOption(Arguments& paras) : Option(paras)
{
    K_ = paras.g_VAL<double>("K");
    cp_ = paras.g_VAL<std::string>("CP");
    paras.g_SET<bool>("simp", new bool(true));
}

double ASOption::payoff(Arguments& paras)
{
    Path* path_ = paras.g_PTR<Path>("path");
    
    if(cp_ == "CALL"&&ff_ == "FIXED"&&ag_ == "ARI")
        return UF::max(0.0, path_->arithmeticAvg() - K_);
    
    if(cp_ == "CALL"&&ff_ == "FIXED"&&ag_ == "ARI")
        return UF::max(0.0, path_->geometricAbg() - K_);
    
    if(cp_ == "CALL"&&ff_ == "FLOATED"&&ag_ == "ARI")
        return UF::max(0.0, path_->paras.g_VAL<double>("ST") - path_->arithmeticAvg());
    
    if(cp_ == "CALL"&&ff_ == "FLOATINGED"&&ag_ == "GEO")
        return UF::max(0.0, path_->paras.g_VAL<double>("ST") - path_->geometricAbg());
    
    if(cp_ == "PUT"&&ff_ == "FIXED"&&ag_ == "ARI")
        return UF::max(0.0, K_ - path_->arithmeticAvg());
    
    if(cp_ == "PUT"&&ff_ == "FIXED"&&ag_ == "GEO")
        return UF::max(0.0, K_ - path_->geometricAbg());
    
    if(cp_ == "PUT"&&ff_ == "FLOATED"&&ag_ == "ARI")
        return UF::max(0.0, path_->arithmeticAvg() - path_->paras.g_VAL<double>("ST"));
    
    if(cp_ == "PUT"&&ff_ == "FLOATED"&&ag_ == "GEO")
        return UF::max(0.0, path_->geometricAbg() - path_->paras.g_VAL<double>("ST"));
    throw OPTCPException();
}
