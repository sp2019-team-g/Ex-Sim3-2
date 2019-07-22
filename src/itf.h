#ifndef ITF_EX32_H
#define ITF_EX32_H

#include "Arguments.h"

#include <vector>
#include <functional>

class itf{
	public:
		virtual std::vector<std::function<void(Arguments)> > inps()=0;
};


#endif
