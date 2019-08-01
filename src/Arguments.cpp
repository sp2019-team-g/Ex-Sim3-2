#include "Arguments.h"

Arguments::Arguments()
{
    args_ = std::map<std::string, void*>();
    desreg_ = std::map<std::string, std::function<void(void)> >();
}

Arguments::~Arguments()
{
    for(
        std::map<std::string,std::function<void(void)> >::iterator it = desreg_.begin();
        it != desreg_.end();
        it++
        )
        (it->second)();
    
}

void Arguments::set(std::string key, void* value, std::function<void(void)>des)
{
    if(args_.find(key) == args_.end())
    {
        args_[key] = value;
        desreg_[key] = des;
    }
    else
    {
        del(key);
        args_[key] = value;
        desreg_[key] = des;
    }
}

void* Arguments::get(std::string key)
{
    return args_[key];
}

void Arguments::del(std::string key)
{
    desreg_[key]();
}

bool Arguments::has(std::string key)
{
    return (args_.find(key)!=args_.end());
}

