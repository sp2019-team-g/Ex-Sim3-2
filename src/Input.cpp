
#include "Input.h"
InputterFile::Input(string input_file_path_)
        :   Data_Fetched_(false)
{

     std::cout<<"Input is from file " << input_file_path_;

    i_stream_.open(input_file_path_.c_str(), std::ios::in);
    if (!i_stream_.is_open())
    {
        throw std::runtime_error("InputterFile:  cannot open input file");
    }

    FetchData();
    WriteMaps();
}

Input::~Input()
{
    i_stream_.close();
}

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  Parameter getters.  Should replace by template versions
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

std::pair<std::string, double> Input::FetchDoublePair()
{
    std::pair<std::string, double> this_pair;
    i_stream_ >> this_pair.first;
    i_stream_ >> this_pair.second;
    return this_pair;
}

std::pair<std::string, char> Input::FetchCharPair()
{
    std::pair<std::string, char> this_pair;
    i_stream_ >> this_pair.first;
    i_stream_ >> this_pair.second;
    return this_pair;
}

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//  FetchData().  Very restrictive.  Up to the client to make the file correspond to this
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

void Input::FetchData()
{
    if (Data_Fetched_) return;

    sc_map_.clear();
    sd_map_.clear();

    sd_map_.insert(FetchDoublePair());        // S0
    sd_map_.insert(FetchDoublePair());        // r
    sd_map_.insert(FetchDoublePair());        // sigma

    sd_map_.insert(FetchDoublePair());        // X
    sd_map_.insert(FetchDoublePair());        // T
    sd_map_.insert(FetchDoublePair());        // kappa

    sd_map_.insert(FetchDoublePair());        // N
    sd_map_.insert(FetchDoublePair());        // M

    sd_map_.insert(FetchDoublePair());        // lambda
    sd_map_.insert(FetchDoublePair());        // eta
    sd_map_.insert(FetchDoublePair());        // nu

    sc_map_.insert(FetchCharPair());          // Application Type
    sc_map_.insert(FetchCharPair());          // Option Type
    sc_map_.insert(FetchCharPair());          // Process Type
    sc_map_.insert(FetchCharPair());          // Method Type
    sc_map_.insert(FetchCharPair());          // Accumulator Type
    sc_map_.insert(FetchCharPair());          // Branching Type
    sc_map_.insert(FetchCharPair());          // Slice Type

    Data_Fetched_ = true;
}

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//	utilities
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

void Input::WriteMaps()
{
    std::cout<<"The following data has been input from file:"<<endl;
    WriteSDmap();
    std::endl;
    WriteSCmap();
    std::cout<<endl;
}

void InputterFile::WriteSDmap()
{
    SD_it it_end = sd_map_.end();
    for(SD_it it = sd_map_.begin(); it != it_end;  ++it )
    {
        ut::OutputLine(it->first, it->second);
    }
}

void InputterFile::WriteSCmap()
{
    SC_it it_end = sc_map_.end();
    for(SC_it it = sc_map_.begin(); it != it_end;  ++it )
    {
        ut::OutputLine(it->first, char(it->second));
    }
}
