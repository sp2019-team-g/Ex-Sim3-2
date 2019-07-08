#ifndef FACTORY_EX32_H
#define FACTORY_EX32_H

#include "Arguments.h"
#include "Process.h"
#include "P32.h"
#include "Option.h"
#include "OptionSim.h"
#include "OptionClo.h"

class Factory{
	public:
		void buildArgument();
		void buildPayoff();
		void buildProcess();
		void buildOption();
	private:
		Arguments arg;
};




#endif
