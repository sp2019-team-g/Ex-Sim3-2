#include <string>
#include "Arguments.h"
using namespace std

class Input
{
public:
    Input(string &);
    ~Input();

    Arguments GetParameters() const {return arguments;}


private:
    Arguments arguments;
    typedef std::map<std::string, double> SD_map;
    typedef std::map<std::string, double>::iterator SD_it;
    typedef std::map<std::string, char> SC_map;
    typedef std::map<std::string, char>::iterator SC_it;

    SD_map sd_map_;
    SC_map sc_map_;

    std::string input_file_path_;

    std::fstream i_stream_;    //Stream for input

    bool Data_Fetched_;

    void FetchData();

    std::pair<std::string, double> FetchDoublePair();
    std::pair<std::string, char> FetchCharPair();

    void WriteMaps();   // utilities
    void WriteSDmap();
    void WriteSCmap();
};
