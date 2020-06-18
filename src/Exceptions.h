//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  Exceptions.h
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
#ifndef EXCEPTIONS_EX32_H
#define EXCEPTIONS_EX32_H
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
#include <exception>
#include <string>
#include <iostream>
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  inverse transform sampling on the cdf of ncx2 may not work properly
//  simply try another initial gauess when this exception encountered
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
struct NC_Exception : public std::exception
{
    public:
        const char * what() const throw(){return "try again";}
};
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  if NC_Exception was throwed too many times, this exception should be
//  throwed to to stop further trying 
//  it might be something wrong with the rv_library, the cdf for cx2 in the
//  rv_library wont return the correct value for some (deltam, lambda) pairs 
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
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
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  when some methods of factory are called before the factory fully built everything
//  this exception should be throwed
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
struct FACNotFinished_Exception : public std::exception
{
    public:
        const char * what() const throw(){return "factory need to be built";}
};
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  if arguments lack of some necessary keys, this exception should be throwed
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
struct ARGRequiredArgNotFound_Exception : public std::exception
{
    public:
        ARGRequiredArgNotFound_Exception(std::string pname){pname_ = pname.c_str();}
        const char * what() const throw(){return pname_;}
    private:
        const char * pname_;
};
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  if para_load of process is not called before pricing, this exception 
//  should be throwed
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
struct PRONotLoaded_Exception : public std::exception
{
    public:
        const char * what() const throw(){return "process not loaded";}
};
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  when a function is called and it should not be, this exception should be throwed
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
struct BadAccess_Exception : public std::exception
{
    public:
        const char * what() const throw(){return "---";}
};

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  xxx
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
struct PTHAbnormal_Exception : public std::exception
{
    public:
        const char * what() const throw(){return " nan encountered during path generating";}
};

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  xxx
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
struct UFBadRVLib_Exception : public std::exception
{
    public:
        const char * what() const throw(){return "rv_library broken";}
};
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  xxx
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
struct BESBadInput_Exception : public std::exception
{
    public:
        BESBadInput_Exception(const char * name, double value) : name_(name), value_(value){}
        const char * what() const throw()
        {
            std::cerr << name_ << " = " << value_ << std::endl;
            return name_;
        }
    private:
        const char * name_;
        double value_;
};
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  xxx
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
struct OPTCPException : public std::exception
{
    public:
        const char * what() const throw(){return "wrong option type";}
};

#endif
//XXXXXXXXXXXXXXXXXXXXXXXXXX
//  End
//XXXXXXXXXXXXXXXXXXXXXXXXXX