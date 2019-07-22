#ifndef OPTION_EX32_H
#define OPTION_EX32_H

#include "Util.h"
#include "Process.h"
#include "Arguments.h"


class Option
{
	public:
		Option(double);
		Option(double, std::function<double(Arguments&)>*);
		Option(Arguments&);
		virtual ~Option(){};
		double get_T();
		virtual double payoff(Arguments&);

	private:
		double T_;
		std::function<double(Arguments&)>* payoff_;
};


#endif
