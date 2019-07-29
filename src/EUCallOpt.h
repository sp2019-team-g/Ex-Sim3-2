#ifndef EUCO_EX32_H
#define EUCO_EX32_H

#include "Option.h"
#include "Util.h"

class EUCallOpt : public Option
{
	public:
		EUCallOpt(double, double);
		EUCallOpt(Arguments&);
<<<<<<< Updated upstream
		double payoff(Arguments&) override;
=======
		double payoff(Arguments&);
>>>>>>> Stashed changes
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
