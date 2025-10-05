#include<bits/stdc++.h>
#define int long long

using namespace std;
const int MOD = 1e9+7;
const int sl = 1e3+5;

int fact[sl];
int ifact[sl];

void process(){
	fact[0] = 1;
	for (int i=1;i<=sl-5;i++){
		fact[i] = fact[i-1]*i;
	}
	ifact[sl-5] = Pow(fact[sl-5],MOD-2);
}

int C(int n, int k){
	
}

signed main(){
	int n;
	cin>>n;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	dp[n][n+1] = 1;
	for (int i=n;i>=1;i--){
		for (int j=n;j>=1;j--){
			if (a[i][j] == '*')	continue;
			dp[i][j] = (dp[i+1][j] + dp[i][j+1])%MOD;
		}
	}
	cout<<dp[1][1]%MOD;
}
