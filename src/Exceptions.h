#ifndef EXCEPTIONS_EX32_H
#define EXCEPTIONS_EX32_H
#include <exception>
class ErrorHandler
{
public:
    void HandleRunTimeError(const std::runtime_error & e);
    void HandleUnknownError();

};


#endif
