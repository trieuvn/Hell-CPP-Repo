#include<bits/stdc++.h>

using namespace std;

const int MAX = 1e6+5;

int n;
int dp[MAX];
int t[MAX];
int r[MAX];

signed main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>t[i];
	}
	for (int i=1;i<=n-1;i++){
		cin>>r[i];
	}
	dp[1] = t[1];
	for (int i=2;i<=n;i++){
		dp[i] = min(dp[i-1] + t[i], dp[i-2] + r[i-1]);
	}
	cout<<dp[n];
}
