
#ifndef PGBM_EX32_H
#define PGBM_EX32_H

#include "Process.h"
#include "Arguments.h"

class PGBM: public Process
{
	public:
		PGBM(double,double,double);
		PGBM(Arguments&);
		void post_update()
		void para_load(Arguments&);
		double simulate();
		double simulate(Arguments&);
		static std::vector<std::function<void(Arguments&)> >plist()
		{
			std::vector<std::function<void(Arguments)> > res();
			res.push_back(g_ASK<double>("mu"));
			res.push_back(g_ASK<double>("sigma"));
			res.push_back(g_ASK<double>("S0"));
			return res;
		}
	private:
		double mu_;
		double sigma_;
		double S0_;


};


#endif
