
#ifndef INPUT_EX32_H
#define INPUT_EX32_H

#include "Arguments.h"

#include <iostream>

class Input
{
	public:
		template<class X> static void buildArg(Arguments& a)
		{
			PLIST xpl = X::plist();
			for(PLIST::iterator it = xpl.begin(); it != xpl.end(); it++)
				it -> operator()(a);
		}

};


#endif
