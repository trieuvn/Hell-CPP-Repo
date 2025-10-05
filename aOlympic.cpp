#include<bits/stdc++.h>

const int MOD = 1e9+7;

const int sl = 5*1e1+5;
using namespace std;

int m,k;

int dp[sl][sl][sl];

int solve(int a, int b, int c){
	//cout<<a<<" "<<b<<" "<<c<<"\n";
	if (a == b && b == c)	return 0;
	if (a >m || b>m || c>m)	return 0;
	//if (dp[a][b][c])	return dp[a][b][c];
	if (a==m || b ==m || c == m){
		if ((a+b+c)%k == 0)
			dp[a][b][c] = 1;
	}
	int s = 0;
	solve(a+1,b,c);
	solve(a,b+1,c);
	solve(a,b,c+1);
	dp[a][b][c] += ((dp[a+1][b][c] +dp[a][b+1][c])%MOD + dp[a][b][c+1])%MOD;
	return dp[a][b][c];
}

signed main(){
	cin>>m>>k;
	int s = 0;
	solve(1,1,0);
	solve(1,0,1);
	solve(0,1,1);
	solve(1,0,0);
	solve(0,1,0);
	solve(0,0,1);
	s += (s + dp[1][1][0])%MOD;
	s += (s + dp[1][0][1])%MOD;
	s += (s + dp[0][1][1])%MOD;
	s += (s + dp[1][0][0])%MOD;
	s += (s + dp[0][1][0])%MOD;
	s += (s + dp[0][0][1])%MOD;
	cout<<s;
}

