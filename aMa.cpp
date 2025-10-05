#include<bits/stdc++.h>
#define int long long

const int MAX = 1e5+5;

const int MOD = 1e9 + 7;

using namespace std;



signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	int dp[MAX];
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i=4;i<=n;i++){
		dp[i] = (dp[i-1] + dp[i-2] + dp[i-3])%MOD;
	}
	cout<<dp[n]%MOD;
}
