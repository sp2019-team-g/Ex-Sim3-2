

#include "Util.h"

#include <iostream>

#include <complex>

using namespace std;
int main(){

//    double tol = 1e-3;


    cout << "I test"<<endl;

    cout << UF::I(complex<double>(0.33,0.12), 4.11 )<<endl;
    cout << UF::I(complex<double>(-0.24,1.32), 2.51 )<<endl;
    cout << UF::I(complex<double>(3.53,2.62), 1.17 )<<endl;
    cout << UF::I(complex<double>(0.73,1.22), 0.61 )<<endl;
    cout<<" b "<<endl;
    cout << "12.259486134636589, -0.13998460121961476"<<endl;
    cout << "5.4489272839914769, 0.5130476413585956" <<endl;
    cout << "0.015148654099080911, 0.024929605388193849"<<endl;
    cout << "-0.25939081859014679, -0.7550570633605812"<<endl;
    cout << "nd test:" << endl;


    cout<<"c"<<endl;
    cout << UF::I(complex<double>(101.00000000485294,0.0009900990098534168) ,51.29306987360073 )<<endl;
    cout<<"\t1.140134697999645e-15 , -1.6183812232275599e-18"<<endl;
    
    auto f = [](double x)->double{
        return 2*x*x + 3*x + 4;
    };
    cout<<UF::numericalDiff(f, 0, 0.03)<<endl;

    cout << "n2d test:" << endl;

    cout<<UF::numericalDiff2(f, 0, 0.03)<<endl;






    cout << "nE test:" << endl;
    cout << UF::normalRnd(0,1)<<endl;

    cout << "c2E test:" << endl;
    cout << UF::chi2Rnd(4.33) << endl;

    cout << "nc2E test:" <<endl;
    cout << UF::ncChi2Rnd(4.1,3.2)<<endl;


	auto f1 = [](double x)->double 
    {
		return x*x*x + 2*x +1;
	};
	cout << "rvs test:" << endl;
	cout << UF::rvs(f1, 4) << endl;


    cout<<"acc test:"<<endl;
    cout<<4.5703224426292e-18/4.57032734666753e-18<<endl;

    cout<<1.75359928797419e-19 / 1.75359928797419e-19 << endl;
    cout<<-1.2616131891979e-19 / 1.75359928797419e-19<<endl;
    cout << 1.2797164540907e-20/1.75359928797419e-19 <<endl;
    return 0;
}


