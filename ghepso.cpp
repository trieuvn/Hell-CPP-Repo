#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>

using namespace std;

vector <long long> vec;

int KTNT(long long x){
	if (x==1||x==0)	return 0;
	if (x==2)	return 1;
	for (long long i=2;i*i<=x;i++){
		if (x%i==0)	return 0;
	}
	return 1;
}

int main(){
	long long n,i,j;
	cin>>n;
	long long test,a[n];
	char x[n];
	for (i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	bool c=false;
	do{
		for (i=0;i<n;i++){
			test = a[i];
			x[i] = test + '0';
			//cout<<a[i];
		}
		test = atoi(x);
		
		if (KTNT(test)==1){
			cout<<test<<"\n";
			c=true;
		}
		strcpy(x,"");
		//cout<<x;
	}while(next_permutation(a,a+n));
	if (c==false){
		cout<<"-1";
	}
}
