#include<bits/stdc++.h>

using namespace std;

const int MAX = 1e6+5;
const int MOD = 14062008;

int n,m;
int dp[MAX];
int a[MAX];

signed main(){
	cin>>n>>m;
	for (int i=0;i<m;i++){
		cin>>a[i];
	}
	a[m] = -1;
	dp[1] = 1;
	dp[0] = 0;
	int j = 0;
	if (a[j] == 0){
		dp[0] = 0;
		j++;
	}
	if (a[j] == 1){
		dp[1] = 0;
		j++;
	}
	
	for (int i=2;i<=n;i++){
		if (i == a[j]){
			dp[i] = 0;
			j++;
		}else{
			dp[i] = (dp[i-1] + dp[i-2])%MOD;
		}
	}
	cout<<dp[n]%MOD;
}
