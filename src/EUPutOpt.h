#ifndef EUPO_EX32_H
#define EUPO_EX32_H

#include "Option.h"

class EUPutOpt : public Option
{
	public: 
		EUPutOpt(double, double);
		EUPutOpt(Arguments&);
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
