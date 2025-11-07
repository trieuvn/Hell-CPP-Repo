#include<bits/stdc++.h>

using namespace std;

int n,m;

int dp[15][205];

void resetDP(){
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			dp[i][j] = 0;
		}
	}
}

int solve(int x, int y, int bit){
	if (bit == 1){
		if (dp[x-1][y] == 1 || dp[x][y-1] == 1){
			return 0;
		}
	}
	if (x == n && y == m){
		return 1;
	}
	if (x == n){
		int l = solve(1,y+1,0);
		dp[1][y+1] = 1;
		int r = solve(1,y+1,1);
		dp[1][y+1] = 0;
		return l + r;
	}else{
		int l = solve(x+1,y,0);
		dp[x+1][y] = 1;
		int r = solve(x+1,y,1);
		dp[x+1][y] = 0;
		return l + r;
	}
}

signed main(){
	cin>>n>>m;
	int l = solve(1,1,0);
	resetDP();
	dp[1][1] = 1;
	int r = solve(1,1,1);
	dp[1][1] = 0;
	cout<<l+r;
}
