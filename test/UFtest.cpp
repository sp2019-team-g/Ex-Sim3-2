

#include "Util.h"

#include <iostream>
using namespace std;
int main(){

//    double tol = 1e-3;

    cout << "nd test:" << endl;
    
    auto f = [](double x)->double{
        return 2*x*x + 3*x + 4;
    };
    cout<<UF::numericalDiff(f, 0, 0.03)<<endl;

    cout << "n2d test:" << endl;

    cout<<UF::numericalDiff2(f, 0, 0.03)<<endl;

    cout << "Phi test:" << endl;
    auto phi = UF::Phi(6.0, 0.1, 0.3);
    for(double i=0; i<10.0;i=i+1)
        cout<<phi(i/1000.0)<<"  ";
    cout<<endl;

    cout << "sum test:" << endl;
    
    auto h = [](int x)->double{
        return (double)x;
    };
    cout << UF::sum(h,0,5)<<endl;


    cout << "nE test:" << endl;
    cout << UF::normalRnd(0,1)<<endl;

    cout << "c2E test:" <<endl;
    cout << UF::ncChi2Rnd(4.1,3.2)<<endl;

    return 0;
}


