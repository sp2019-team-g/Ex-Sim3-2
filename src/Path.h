#ifndef PATH_EX32_H
#define PATH_EX32_H

#include "Arguments.h"
#include "Process.h"

#include <vector>

class Path{
	public:
		Path();
		Path(double, double, Process*);
		Path(Arguments);
	private:
		std::vector<double> path_;
		double dt_;
		double t0_;


};

#endif

