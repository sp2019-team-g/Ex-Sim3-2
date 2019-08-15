//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  Factory.h
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
#ifndef FACTORY_EX32_H
#define FACTORY_EX32_H
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
#include "Arguments.h"
#include "Process.h"
#include "PricingEng.h"
#include "Option.h"
#include "Input.h"
#include "CSVLogger.h"
#include "Exceptions.h"

#include <vector>
#include <string>


#include <iostream>
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  Factory class : 
//      build necessary parts for pricing an option
//      template requirements:
//          PS, a class derived from Process
//          PE, a class derived from PricingEng
//          OP, a class derived from Option
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
template<class PS,class PE,class OP> class Factory
{
    public:
        //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
        //  Factory(): constructor
        //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
        Factory():arg_(Arguments()){done_ = false;}
        //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
        //  inp(): ask for all required parameters from stdin
        //      return (void):
        //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
        void inp()
        {
            Input::buildArg<PS>(arg_);
            Input::buildArg<PE>(arg_);
            Input::buildArg<OP>(arg_);
        }
        //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
        //  build(): build option, pricingeng and process pointer
        //      return (void): 
        //      arg requirements:
        //          "verbose" (bool): optional, print details when its on
        //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
        void build()
        {
            if(arg_.has("verbose"))
                std::cout << "building..."<<std::endl;
            Option* op = new OP(arg_);
            arg_.g_SET<Option>("option", op);
            op_ = op;
            Process* ps = new PS(arg_);
            arg_.g_SET<Process>("process", ps);
            ps_ = ps;
            pe_ = new PE(arg_);
            done_ = true;
        }
        //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
        //  SET(string key, T* a): insert a key, value pair into arguments
        //      key (string): name of the variable
        //      a (T*): pointer to the variable
        //      return (void):
        //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
        template<class T> void SET(std::string key, T * a){arg_.g_SET<T>(key, a);}
        //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
        //  get_arg(): get current arguments
        //      return (Arguments): the current arguments
        //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
        Arguments& get_arg(){return arg_;}
        //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
        //  get_ps(): getter for process
        //      return (Process*): pointer to the built process
        //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
        Process* get_ps()
        {
            if(!done_)
                throw FACNotFinished_Exception();
            return ps_;
        }
        //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
        //  get_op(): getter for option
        //      return (Option*): pointer to the built option
        //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
        Option* get_op()
        {
            if(!done_)
                throw FACNotFinished_Exception();
            return op_;
        }
        //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
        //  get_pe(): getter for pricing engine
        //      return (PricingEng*): pointer to the built pricing engine
        //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
        PricingEng* get_pe(){return pe_;}
        //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
        //  price(): pricing the option base on pe and ps
        //      return (double): price
        //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
        double price()
        {
            if(!done_)
                throw FACNotFinished_Exception();
            return pe_ -> price(arg_);
        }

    private:
        Arguments arg_;
        Process* ps_;
        PricingEng* pe_;
        Option* op_;
        bool done_;

};




#endif
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  End
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX