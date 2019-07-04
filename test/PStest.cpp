#include "Process.h"

using namespace std;

int main(){

    Process p(0.0,1.0);
    cout<<p.get_t()<<endl;
    cout<<p.get_T()<<endl;
    cout<<p.get_dt()<<endl;
    p.set_t(0.5);
    cout<<p.get_t()<<endl;
    cout<<p.get_dt()<<endl;
    return 0;
}
