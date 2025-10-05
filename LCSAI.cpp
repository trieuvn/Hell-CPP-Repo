#include <bits/stdc++.h>
using namespace std;

int main() {
    long a,b;
    cin>>a>>b;
    if (a ==0 ){
    	if (b==0){
    		cout<<"INFINITE SOLUTIONS";
    		return 0;
		}else{
			cout<<"NO SOLUTION";
			return 0;
		}
	}
	if ((-b%a) != 0 ){
		cout<<"NO SOLUTION";
		return 0;
	}
	else {
		cout<<-b/a;
	}
    return 0;
}
