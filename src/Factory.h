#ifndef FACTORY_EX32_H
#define FACTORY_EX32_H

#include "Arguments.h"
#include "Process.h"
#include "PricingEng.h"
#include "Option.h"
#include "Input.h"

#include <vector>
// #include <iostream>
// using namespace std;

template<class PS,class PE,class OP>
class Factory{
	public:
		Factory():arg_(Arguments())
		{
			done_ = false;
		}

		void build()
		{
			Input::buildArg<PS>(arg_);
			Input::buildArg<PE>(arg_);
			Input::buildArg<OP>(arg_);

			Option* op = new OP(arg_);

			arg_.g_SET<Option>("option", op);
			
			op_ = op;
			Process* ps = new PS(arg_);

			arg_.g_SET<Process>("process", ps);

			ps_ = ps;


			pe_ = new PE(arg_);

			done_ = true;
		}
		Arguments& get_arg()
		{
			/* todo:
			 * check done_, throw exp
			 * */
			return arg_;
		}
		Process* get_ps()
		{
			return ps_;
		}
		Option* get_op()
		{
			return op_;
		}
		PricingEng* get_pe()
		{
			return pe_;
		}
	private:
		Arguments arg_;
		Process* ps_;
		PricingEng* pe_;
		Option* op_;
		bool done_;

};




#endif
