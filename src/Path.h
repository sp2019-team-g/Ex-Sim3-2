#ifndef PATH_EX32_H
#define PATH_EX32_H



#include <vector>
#include <iostream>

class Arguments;
class Process;
class Path{
	public:
		Path(double, double, double, std::vector<double>&);
		Path(Arguments&);

		void add(double);
		double arithmeticAvg();
		double geometricAbg();
		bool break_up(double);
		bool break_down(double);
		double max();
		double min();

		friend std::ostream& operator<<(std::ostream&, Path*);
		friend std::ostream& operator<<(std::ostream&, Path);
	private:	
		double t_;
		double dt_;
		double T_;
		std::vector<double> path_;
};

#endif

