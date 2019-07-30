#include "Process.h"
#include <iostream>
using namespace std;

int main(){

    Process p(1.0);

    cout<<p.get_dt()<<endl;

    p.set_loaded(true);
    cout<<p.check_loaded()<<endl;


    return 0;
}
