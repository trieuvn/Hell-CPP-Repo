#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1e5+5;

int n,m;
int dp[MAX];
int dpm[MAX];

signed main(){
	dp[0] = 0;
	dp[1] = 1;
	
	for (int i=1;i<=MAX;i++){
		dp[(2*i)] = dp[i];
		dp[(2*i+1)] = dp[i] + dp[i+1];
	}
	dpm[0] = 0;
	dpm[1] = 1;
	
	for (int i=2;i<MAX;i++){
		dpm[i] = max(dpm[i-1], dp[i]);
		//cout<<dpmax[i]<<" ";
	}
	cin>>n;
	
	int input;
	for (int i=0;i<n;i++){
		cin>>input;
		cout<<dpm[input]<<"\n";
	}
}
