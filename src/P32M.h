#ifndef P32M_EX32_H
#define P32M_EX32_H

#include "Util.h"
#include "Process.h"
#include "Arguments.h"

#include <complex_bessel.h>

#include <vector>
#include <functional>
#include <complex>


class P32M : public Process
{
	public:
		P32M(double, double, double, double, double, double);
		P32M(Arguments&);
		void post_update();
		void para_load(Arguments&);
		double simulate();
		double simulate(Arguments&);
		static PLIST plist()
		{
            PLIST res;
            res.push_back(g_ASK<double>("r"));
            res.push_back(g_ASK<double>("rho"));
            res.push_back(g_ASK<double>("kappa"));
            res.push_back(g_ASK<double>("theta"));
            res.push_back(g_ASK<double>("epsilon"));
            res.push_back(g_ASK<double>("dt"));
            res.push_back(g_ASK<double>("S0"));
            res.push_back(g_ASK<double>("V0"));
            res.push_back(g_ASK<size_t>("N"));
            return res;
		}

	private:
		double r_;
		double rho_;
		
};




#endif
