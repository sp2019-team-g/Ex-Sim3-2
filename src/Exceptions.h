#ifndef EXCEPTIONS_EX32_H
#define EXCEPTIONS_EX32_H
#include <exception>
#include <string>
#include <iostream>
struct NC_Exception : public std::exception
{
    public:
        const char * what() const throw(){return "try again";}
};

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

struct FACNotFinished_Exception : public std::exception
{
    public:
        const char * what() const throw(){return "factory need to be built";}
};

struct ARGRequiredArgNotFound_Exception : public std::exception
{
    public:
        ARGRequiredArgNotFound_Exception(std::string pname){pname_ = pname.c_str();}
        const char * what() const throw(){return pname_;}
    private:
        const char * pname_;
};

struct PRONotLoaded_Exception : public std::exception
{
    public:
        const char * what() const throw(){return "process not loaded";}
};

struct BadAccess_Exception : public std::exception
{
    public:
        const char * what() const throw(){return "---";}
};

#endif
