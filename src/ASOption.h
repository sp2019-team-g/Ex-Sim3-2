//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  ASOption.h
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
#ifndef ASOPT_EX32_H
#define ASOPT_EX32_H
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
#include "Arguments.h"
#include "Option.h"

#include <string>

class ASOption : public Option
{
    public:
        ASOption(Arguments&);
        double payoff(Arguments&) override;
        static PLIST plist()
        {
            PLIST res;
            res.push_back(g_ASK<double>("K"));
            res.push_back(g_ASK<double>("T"));
            res.push_back(g_ASK<std::string>("CP"));
            res.push_back(g_ASK<std::string>("FF"));
            res.push_back(g_ASK<std::string>("AG"));
            return res;
        }
    private:
        double K_;
        std::string cp_;
        std::string ff_;
        std::string ag_;
};

#endif

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  End
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
