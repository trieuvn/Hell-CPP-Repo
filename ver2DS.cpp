#include<bits/stdc++.h>

using namespace std;

int main(){
	int k,i,test;
	unsigned long long n;
	cin>>k;
	for (i=0;i<k;i++){
		cin>>n;
		test = n%10;
		if (test == 1)	cout<<"4";
		if (test == 2)	cout<<"9";
		if (test == 3)	cout<<"6";
		if (test == 4)	cout<<"5";
		if (test == 5)	cout<<"6";
		if (test == 6)	cout<<"9";
		if (test == 7)	cout<<"4";
		if (test == 8)	cout<<"1";
		if (test == 9)	cout<<"0";
		if (test == 0)	cout<<"1";
		cout<<"\n";
	}
}
