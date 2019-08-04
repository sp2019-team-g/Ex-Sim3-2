#ifndef ASCO_EX32_H
#define ASCO_EX32_H
#include "Arguments.h"
#include "Option.h"

class ASCallOpt : public Option
{
public:
	ASCallOpt(double, double);
	ASCallOpt(Arguments&);
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
