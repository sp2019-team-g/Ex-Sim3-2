#ifndef OPTIONSIM_EX32_H
#define OPTIONSIM_EX32_H
#include "Option.h"
#include "Arguments.h"

class OptionSim : public Option
{
	public:
		OptionSim(double, double, double, size_t, Process*);
		double price();
	private:
		double S0;
		size_t batch_size;

};



#endif
