//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  EUOption.h
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
#ifndef EUCO_EX32_H
#define EUCO_EX32_H
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
#include "Arguments.h"
#include "Option.h"

#include <string>

class EUOption : public Option
{
    public:
        EUOption(double, double, std::string);
        EUOption(Arguments&);
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
        std::string cp_;
};

#endif

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  End
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
