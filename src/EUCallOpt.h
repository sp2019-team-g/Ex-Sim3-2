#ifndef EUCO_EX32_H
#define EUCO_EX32_H
#include "Arguments.h"
#include "Option.h"


class EUCallOpt : public Option
{
    public:
        EUCallOpt(double, double);
        EUCallOpt(Arguments&);
        double payoff(Arguments&) override;
        static PLIST plist()
        {
            PLIST res;
            res.push_back(g_ASK<double>("K"));
            res.push_back(g_ASK<double>("T"));
            return res;
        }
        
    private:
        double K_;
};

#endif
//XXXXXXXXXXXXXXXXXXXXXXXXXX
//  End
//XXXXXXXXXXXXXXXXXXXXXXXXXX