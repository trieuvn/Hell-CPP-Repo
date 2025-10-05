#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	long long n,i;
	cin>>n;
	long long a[n];
	for (i=0;i<n;i++){
		cin>>a[i];
	}
	for (i=0;i<n;i++){
		if (a[i]%3==0)	continue;
		cout<<a[i]<<" ";
	}
	cout<<"\n";
	for (i=0;i<n;i++){
		if (a[i]%3==0 || a[i]%5==0)	continue;
		cout<<a[i]<<" ";
	}
}
