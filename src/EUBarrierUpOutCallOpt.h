#ifndef EUBUOCO_EX32_H
#define EUBUOCO_EX32_H
#include "Arguments.h"
#include "Option.h"

class EUBarrierUpOutCallOpt : public Option
{
public:
	EUBarrierUpOutCallOpt(double, double);
	EUBarrierUpOutCallOpt(Arguments&);
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
