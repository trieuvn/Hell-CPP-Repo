#include<bits/stdc++.h>
#define int int64_t

using namespace std;

const int MAX = 1e5+5;
const int INF = 1e18;

int n,x;
int a[MAX];
int dp[MAX][3];

signed main(){
	cin>>n>>x;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=0;i<=n;i++){
		dp[i][1] = -INF;
		dp[i][2] = -INF;
	}
	for (int i=1;i<=n;i++){
		dp[i][0] = max(dp[i-1][0] + a[i], a[i]);
		dp[i][1] = max(dp[i-1][0] + a[i]*x, dp[i-1][1] + a[i]*x);
		dp[i][1] = max(dp[i][1], a[i]*x);
		dp[i][2] = max(dp[i-1][2] + a[i], dp[i-1][1] + a[i]);
	}
	int res = 0;
	for (int i=1;i<=n;i++){
		res = max(res, dp[i][0]);
		res = max(res, dp[i][1]);
		res = max(res, dp[i][2]);
	}
	cout<<res;
}
