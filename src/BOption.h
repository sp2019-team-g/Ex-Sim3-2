//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  BOption.h
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
#ifndef BOPT_EX32_H
#define BOPT_EX32_H
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
#include "Arguments.h"
#include "Option.h"
#include <string>

class BOption : public Option
{
    public:
        BOption(Arguments&);
        double payoff(Arguments&) override;
        static PLIST plist()
        {
            PLIST res;
            res.push_back(g_ASK<double>("K"));
            res.push_back(g_ASK<double>("T"));
            res.push_back(g_ASK<std::string>("CP"));
            res.push_back(g_ASK<std::string>("UD"));
            res.push_back(g_ASK<std::string>("IO"));
            return res;
        }

    private:
        double K_;
        double B_;
        std::string cp_;
        std::string ud_;
        std::string io_;
};

#endif

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  End
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
