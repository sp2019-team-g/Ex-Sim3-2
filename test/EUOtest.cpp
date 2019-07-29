#include "EUCallOpt.h"
#include "EUPutOpt.h"
#include "Arguments.h"
#include <iostream>
#include <string>
using namespace std;

int main(){
	EUPutOpt p = EUPutOpt(0.5,1.33);
	EUCallOpt c = EUCallOpt(0.3,1.22);
	Arguments a = Arguments();
	a.g_SET<double>("ST", new double(1.12));
	a.g_SET<double>("T", new double(3.2));
	a.g_SET<double>("K", new double(0.21));
	EUCallOpt cc = EUCallOpt(a);
	EUPutOpt pp = EUPutOpt(a);

	cout<<c.payoff(a)<<endl;
	cout<<p.payoff(a)<<endl;
	cout<<cc.payoff(a)<<endl;
	cout<<pp.payoff(a)<<endl;
<<<<<<< Updated upstream
=======
	PLIST pl = EUCallOpt::plist();
	for(auto it = pl.begin(); it != pl.end();pl++){
		it->operator()(a);
	}
	
>>>>>>> Stashed changes

	return 0;
}