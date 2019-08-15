//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  CSVLogger.cpp
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
#include "CSVLogger.h"
#include "Arguments.h"
#include <iostream>
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  CSVLogger::CSVLogger
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
CSVLogger::CSVLogger(Arguments& paras)
{
    fname_ = paras.g_VAL<std::string>("csv_name");
    std::vector<std::string> title = paras.g_VAL<std::vector<std::string> >("csv_title");
    ofs_ = new std::ofstream(fname_, std::ofstream::out);
    N_ = title.size() + 1;
    cnt_ = 0;
    (*ofs_) << "#";
    for
        (
            std::vector<std::string>::iterator it = title.begin();
            it != title.end();
            it++
        )
        (*ofs_) << "," << *it;
    (*ofs_) << '\n';
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  CSVLogger::~CSVLogger
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
CSVLogger::~CSVLogger(){
    std::cout << "ss"<< std::endl;
    ofs_ -> close();
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  CSVLogger::add
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
void CSVLogger::add(std::vector<double> row)
{
    (*ofs_) << cnt_++;
    for
        (
            std::vector<double>::iterator it = row.begin();
            it != row.end();
            it++
        )
        (*ofs_) << "," << *it;
    (*ofs_) << '\n';
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  CSVLogger::add
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
void CSVLogger::add(double* row)
{
    (*ofs_) << cnt_++;
    for(size_t i = 0; i < N_ - 1; i++)
        (*ofs_) << "," << *(row + i);
    (*ofs_) << '\n';
}


//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// End
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX