#ifndef OPTION_EX32_H
#define OPTION_EX32_H

#include "Util.h"
#include "Process.h"

class Option
{
	public:
		Option(double, double);
		Option(Arguments);
		virtual ~Option(){};
		double get_T();
		double get_K();
		virtual double price(){return 0.0;};
	private:
		double K_;
		double T_;
};


#endif