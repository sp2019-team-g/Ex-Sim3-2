#ifndef ASPP_EX32_H
#define ASPP_EX32_H
#include "Arguments.h"
#include "Option.h"

class ASPutOpt : public Option
{
public:
	ASPutOpt(double, double);
	ASPutOpt(Arguments&);
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
