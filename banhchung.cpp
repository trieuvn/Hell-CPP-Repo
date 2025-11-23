#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 5e3+5;

int n,m;
int a[MAX];
int c[MAX];
long double dp[505][10005];

long double solve(int cur, int a1, int a2, int c1, int c2, int sl1, int sl2){
	if (dp[sl1][sl2] != 0){
		return dp[cur][sl1][sl2];
	}
	if (cur == 0){
		if (a1 < m || a2 < m)	return dp[cur][sl1][sl2] = LONG_MAX;
		if (sl1 == m || sl2 == m)
			return dp[cur][sl1][sl2] = ((long double)c1/a1) * ((long double)c2/a2);
		return dp[cur][sl1][sl2] = LONG_MAX;
	}
	
	long double cho1 = solve(cur-1,a1+a[cur],a2,c1+c[cur],c2,sl1+1,sl2);
	long double cho2 = solve(cur-1,a1,a2+a[cur],c1,c2+c[cur],sl1,sl2+1);
	return dp[cur][sl1][sl2] = min(cho1,cho2);
}

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n;i++){
		cin>>c[i];
	}
	cout<<setprecision(3)<<fixed<<solve(n,0,0,0,0,0,0);
}
