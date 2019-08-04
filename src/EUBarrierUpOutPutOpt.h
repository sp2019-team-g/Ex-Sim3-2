#ifndef EUBUOPO_EX32_H
#define EUBUOPO_EX32_H
#include "Arguments.h"
#include "Option.h"

class EUBarrierUpOutPutOpt : public Option
{
public:
	EUBarrierUpOutPutOpt(double, double);
	EUBarrierUpOutPutOpt(Arguments&);
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
