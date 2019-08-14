//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  ASOption.h
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
#ifndef ASCO_EX32_H
#define ASCO_EX32_H
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
#include "Arguments.h"
#include "Option.h"

#include <string>

class ASOption : public Option
{
    public:
        ASOption(double, double, std::string);
        ASOption(Arguments&);
        double payoff(Arguments&) override;
        static PLIST plist()
        {
            PLIST res;
            res.push_back(g_ASK<double>("K"));
            res.push_back(g_ASK<double>("T"));
            res.push_back(g_ASK<std::string>("CP"));
            return res;
        }
    private:
        double K_;
        std::string cp_;//CALL PUT
        std::string ff_;//FIXED FLOATED
        std::string ag_;//ARI GEO
};

#endif

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  End
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
