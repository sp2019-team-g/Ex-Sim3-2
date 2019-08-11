#ifndef ASPRICINGENG_EX32_H
#define ASPRICINGENG_EX32_H

#include "PricingEng.h"
#include "Arguments.h"

class Option;
class Process;

class McPricingAS : public PricingEng
{
    public:
        McPricingAS(Option*, Process*);
        McPricingAS(Arguments&);
        double price();
        double price(Arguments&);
        static PLIST plist()
        {
            PLIST res;
            res.push_back(g_ASK<size_t>("nos"));
            res.push_back(g_ASK<double>("T"));
            return res;
        }

    private:
        Process* pro_;
};


#endif
