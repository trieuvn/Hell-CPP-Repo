#include<bits/stdc++.h>
#define int int64_t

using namespace std;

const int MAX = 1e5+5;
const int INF = 1e18;
const int MOD = 1e9+7;

int n,k,q;
int a[MAX];
int b[MAX];
map<int,int> dp;
int brokenlist[MAX];
int brokenlatelist[MAX];
map<int,bool> isbroken;

int solve(int vtbroken){
	if (vtbroken == -1){
		dp[0] = 1;
		for (int i=1;i<=n;i++){
			if (isbroken[i] == true){
				dp[i] = 0;
				continue;
			}
			if (i-1 >= 0){
				dp[i] = (dp[i] + dp[i-1])%MOD;
			}
			if (i-2 >= 0){
				dp[i] = (dp[i] + dp[i-2])%MOD;
			}
			if (i-3 >= 0){
				dp[i] = (dp[i] + dp[i-3])%MOD;
			}
		}
		return dp[n]%MOD;
	}else{
		dp[vtbroken] = 0;
		for (int i=vtbroken;i<=n;i++){
			dp[i] = 0;
			if (isbroken[i] == true){
				dp[i] = 0;
				continue;
			}
			if (i-1 >= 0){
				dp[i] = (dp[i] + dp[i-1])%MOD;
			}
			if (i-2 >= 0){
				dp[i] = (dp[i] + dp[i-2])%MOD;
			}
			if (i-3 >= 0){
				dp[i] = (dp[i] + dp[i-3])%MOD;
			}
		}
		return dp[n]%MOD;
	}
	
}

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k>>q;
	for (int i=0;i<k;i++){
		cin>>brokenlist[i];
		isbroken[brokenlist[i]] = true;
	}
	cout<<solve(-1)<<"\n";
	int preres=-1;
	for (int t=0;t<q;t++){
		cin>>brokenlatelist[t];
		isbroken[brokenlatelist[t]] = true;
		if (preres == 0){
			cout<<0<<"\n";
		}else{
			preres = solve(brokenlatelist[t]);
			cout<<preres<<"\n";
		}
		
	}
}
