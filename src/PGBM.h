
#ifndef PGBM_EX32_H
#define PGBM_EX32_H

#include "Process.h"
#include "Arguments.h"

class PGBM: public Process
{
	public:
		PGBM(double,double,double);
		PGBM(Arguments);
		void post_update()
		void para_load(Arguments);
		double simulate();
		double simulate(Arguments);

	private:
		double mu_;
		double sigma_;
		double S0_;


}


#endif
