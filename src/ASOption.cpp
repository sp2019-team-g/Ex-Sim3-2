//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  ASOption.cpp
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
#include "ASOption.h"
#include "Path.h"
#include "Util.h"
#include "Exceptions.h"
ASOption::ASOption(Arguments& paras) : Option(paras)
{
	cp_ = paras.g_VAL<std::string>("CP");
	ff_ = paras.g_VAL<std::string>("FF");
	ag_ = paras.g_VAL<std::string>("AG");

}

double ASOption::payoff(Arguments& paras)
{
	Path * pth = paras.g_PTR<Path>("path");
	double ST = paras.g_VAL<double>("ST");
	double avg = 0.0;
	double K = 0.0;
	double cpd = 0.0;
	if(ff_ == "RATE") K = paras.g_VAL<double>("K");
	if(ag_ == "ARI") avg = pth -> arithmeticAvg();
	else if(ag_ == "GEO") avg = pth -> geometricAvg();
	else throw OPTCPException();
	if(ff_ == "RATE") ST = avg;
	else if(ff_ == "STRIKE") K = avg;
	else throw OPTCPException();
	if(cp_ == "CALL") cpd = 1.0;
	else if(cp_ == "PUT") cpd = -1.0;
	else throw OPTCPException();
	return UF::max(cpd * (ST - K), 0.0);
}



//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  End
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
