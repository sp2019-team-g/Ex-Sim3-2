//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  Factory.h
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
#ifndef FACTORY_EX32_H
#define FACTORY_EX32_H
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
#include "Arguments.h"
#include "Process.h"
#include "PricingEng.h"
#include "Option.h"
#include "Input.h"
#include "Exceptions.h"

#include <vector>
#include <string>


#include <iostream>
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  Factory class : 
//      build necessary parts for pricing an option
//      template requirements:
//          PS, a class derived from Process
//          PE, a class derived from PricingEng
//          OP, a class derived from Option
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
template<class PS,class PE,class OP> class Factory
{
    public:
        //**************************
        //  Factory(): constructor
        //**************************
        Factory():arg_(Arguments()){done_ = false;}
        //**************************
        //  inp(): ask for all required parameters from stdin
        //      return (void):
        //**************************
        void inp()
        {
            Input::buildArg<PS>(arg_);
            Input::buildArg<PE>(arg_);
            Input::buildArg<OP>(arg_);
        }
        //**************************
        //  build(): build option, pricingeng and process pointer
        //      return (void): 
        //      arg requirements:
        //          "verbose" (bool): optional, print details when its on
        //**************************
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
    
        //**************************
        //  SET(string key, T* a): insert a key, value pair into arguments
        //      key (string): name of the variable
        //      a (T*): pointer to the variable
        //      return (void):
        //**************************
        template<class T> void SET(std::string key, T * a){arg_.g_SET<T>(key, a);}
        //**************************
        //  get_arg(): get current arguments
        //      return (Arguments): the current arguments
        //**************************
        Arguments& get_arg(){return arg_;}
        //**************************
        //  get_ps(): getter for process
        //      return (Process*): pointer to the built process
        //**************************
    
        Process* get_ps()
        {
            if(!done_)
                throw FACNotFinished_Exception();
            return ps_;
        }
    
        //**************************
        //  get_op(): getter for option
        //      return (Option*): pointer to the built option
        //**************************
    
        Option* get_op()
        {
            if(!done_)
                throw FACNotFinished_Exception();
            return op_;
        }
    
        //**************************
        //  get_pe(): getter for pricing engine
        //      return (PricingEng*): pointer to the built pricing engine
        //**************************
       
    PricingEng* get_pe(){return pe_;}
    
        //**************************
        //  price(): pricing the option base on pe and ps
        //      return (double): price
        //**************************
        
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

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  End
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
