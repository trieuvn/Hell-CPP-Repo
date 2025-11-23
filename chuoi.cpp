#include<bits/stdc++.h>

using namespace std;

const int MAX = 5e5+5;

int n,k;
int a[MAX];
int c1;

signed main(){
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i];
		if (a[i] == 1){
			c1++;
		}
	}
	sort(a,a+n);
	for (int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	//cout<<n-c1-1;
}
