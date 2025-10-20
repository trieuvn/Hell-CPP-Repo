#include<bits/stdc++.h>
#define ing long long

using namespace std;
const int MOD = 1e9+7;
const int MAX = 1e6+5;

int n, x;
int c[105];
int dp[MAX];

signed main(){
	cin>>n>>x;
	for (int i=0;i<n;i++){
		cin>>c[i];
	}
	dp[0] = 1;
	for (int i=0;i<n;i++){
		for (int j=0;j<=x;j++){
			if (j-c[i]>=0){
				dp[j] = (dp[j-c[i]] + dp[j])%MOD;
			}
		}
	}
	cout<<dp[x]%MOD;
}
