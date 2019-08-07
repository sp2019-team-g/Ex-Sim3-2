//XXXXXXXXXXXXXXXXXXXXXXXXXX
//  Exceptions.h
//XXXXXXXXXXXXXXXXXXXXXXXXXX
#ifndef EXCEPTIONS_EX32_H
#define EXCEPTIONS_EX32_H
//XXXXXXXXXXXXXXXXXXXXXXXXXX
#include <exception>
#include <string>
#include <iostream>
//XXXXXXXXXXXXXXXXXXXXXXXXXX
//  inverse transform sampling on the cdf of ncx2 may not work properly
//  simply try another initial gauess when this exception encountered
//XXXXXXXXXXXXXXXXXXXXXXXXXX
struct NC_Exception : public std::exception
{
    public:
        const char * what() const throw(){return "try again";}
};
//XXXXXXXXXXXXXXXXXXXXXXXXXX
//  if NC_Exception was throwed too many times, this exception should be
//  throwed to to stop further trying 
//  it might be something wrong with the rv_library, the cdf for cx2 in the
//  rv_library wont return the correct value for some (deltam, lambda) pairs 
//XXXXXXXXXXXXXXXXXXXXXXXXXX
struct NCDead_Exception : public std::exception
{
    public:
        NCDead_Exception(double delta, double lambda) : delta_(delta), lambda_(lambda){}
        const char * what() const throw()
        {
            std::cerr << "delta: " << delta_ << "," << "lambda: " << lambda_ << std::endl;
            return "nc chi 2 dead.";
        }
    private:
        double delta_;
        double lambda_;
};
//XXXXXXXXXXXXXXXXXXXXXXXXXX
//  when some methods of factory are called before the factory fully built everything
//  this exception should be throwed
//XXXXXXXXXXXXXXXXXXXXXXXXXX
struct FACNotFinished_Exception : public std::exception
{
    public:
        const char * what() const throw(){return "factory need to be built";}
};
//XXXXXXXXXXXXXXXXXXXXXXXXXX
//  if arguments lack of some necessary keys, this exception should be throwed
//XXXXXXXXXXXXXXXXXXXXXXXXXX
struct ARGRequiredArgNotFound_Exception : public std::exception
{
    public:
        ARGRequiredArgNotFound_Exception(std::string pname){pname_ = pname.c_str();}
        const char * what() const throw(){return pname_;}
    private:
        const char * pname_;
};
//XXXXXXXXXXXXXXXXXXXXXXXXXX
//  if para_load of process is not called before pricing, this exception 
//  should be throwed
//XXXXXXXXXXXXXXXXXXXXXXXXXX
struct PRONotLoaded_Exception : public std::exception
{
    public:
        const char * what() const throw(){return "process not loaded";}
};
//XXXXXXXXXXXXXXXXXXXXXXXXXX
//  when a function is called and it should not be, this exception should be throwed
//XXXXXXXXXXXXXXXXXXXXXXXXXX
struct BadAccess_Exception : public std::exception
{
    public:
        const char * what() const throw(){return "---";}
};


struct PTHAbnormal_Exception : public std::exception
{
    public:
        const char * what() const throw(){return " nan encountered during path generating";}
};


struct UFBadRVLib_Exception : public std::exception
{
    public:
        const char * what() const throw(){return "rv_library broken";}
};
#endif
//XXXXXXXXXXXXXXXXXXXXXXXXXX
//  End
//XXXXXXXXXXXXXXXXXXXXXXXXXX