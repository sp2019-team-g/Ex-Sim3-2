#include "EUOption.h"
#include "Arguments.h"
#include <iostream>
#include <string>
using namespace std;

int main(){
	EUOption p = EUOption(0.5,1.33,"PUT");
	EUOption c = EUOption(0.3,1.22,"CALL");
	Arguments a = Arguments();
	a.g_SET<double>("ST", new double(1.12));
	a.g_SET<double>("T", new double(3.2));
	a.g_SET<double>("K", new double(0.21));
	EUOption cc = EUOption(a);
	EUOption pp = EUOption(a);

	cout<<c.payoff(a)<<endl;
	cout<<p.payoff(a)<<endl;
	cout<<cc.payoff(a)<<endl;
	cout<<pp.payoff(a)<<endl;


	PLIST pl = EUOption::plist();
	for(auto it = pl.begin(); it != pl.end(); it++){
		it->operator()(a);
	}


	return 0;
}