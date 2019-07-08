#ifndef OPTION_EX32_H
#define OPTION_EX32_H

#include "Util.h"
#include "Process.h"

class Option
{
	public:
		Option(double, double, std::function<double(Arguments)>*);
		Option(Arguments);
		virtual ~Option(){};
		double get_T();
		double get_K();
		virtual double price(){return 0.0;};
		double payoff(Arguments);
	private:
		double K_;
		double T_;
		std::function<double(Arguments)>* payoff_;
};


#endif