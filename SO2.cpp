#include <iostream>
#include <math.h>

using namespace std;

int main(){
	unsigned long long a,b,max;
	cin >>a;
	cin >>b;
	unsigned long long test;
	for (unsigned long long i=1;i*i<=a;++i){
		if (a%i==0){
			if (b%i==0)	max=i;
			test =a/i;
			if (i != test){
				if ((b%test)==0){
					cout<<test<<"huh";
					return 0;
				}
			}
		}
	
	}
	cout <<max<<".";
}
