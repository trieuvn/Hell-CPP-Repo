#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1e5+5;

int n;
int a,b;
int A[MAX];
int res = 0;

int LCM(int a, int b){
	for (int i=1;i<=b;i++){
		if (a*i % b == 0){
			return a*i;
		}
	}
	return a*b;
}

void build(int pos){
	if (pos >= n){
		return ;
	}
	for (int i=1;i<=n;i++){
		
	}
}

signed main(){
	cin>>n;
	for (int i=0;i<q;i++){
		cin>>I[i]>>J[i]>>K[i];
	}
	
	build(0);
	cout<<res;
}
