#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 25;

int n;
int a[MAX][MAX];
int start;
int dp[23][(1<<20)+2];

int solve(int cur, int vis){
	if (vis == (1<<n) -1){
		return a[cur][start];
	}
	
	if (dp[cur][vis] != -1){
		return dp[cur][vis];
	}
	int Min = LONG_MAX;
	for (int i=1;i<=n;i++){
		if (((1<<(i-1)) & vis) != 0) continue;
		//vis = vis | (1<<(i-1));
		Min = min(Min, a[cur][i] + solve(i,vis | (1<<(i-1))));
		//vis = vis & ~(1<<(i-1));
	}
	return dp[cur][vis] = Min;
}

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	
	memset(dp, -1, sizeof(dp));
	
	start = 1;
	
	int initial_mask = (1 << (start - 1)); 
	
	int Min = solve(start, initial_mask);
	cout<<Min;
}
