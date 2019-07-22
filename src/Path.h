#ifndef PATH_EX32_H
#define PATH_EX32_H

#include "Arguments.h"
#include "Process.h"

#include <vector>

class Path{
	public:
		Path(double, double, double, std::vector<double> );
		Path(Arguments&);
		void add(double);
	
	private:	
		double t_;
		double dt_;
		double T_;
		std::vector<double> path_;
		


};

#endif

