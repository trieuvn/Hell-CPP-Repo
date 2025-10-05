#include <bits/stdc++.h>
using namespace std;
const int sl = 5005;

const int MOD = 76213;
vector<int> dp(sl,-1);

int solve(int n){
	if (dp[n] != -1) return dp[n];
	dp[n] = (n-1) * (solve(n-1) + solve(n-2));
	return dp[n];
}

signed main() {
    int n;
    cin>>n;
    dp[1] = 0;
    dp[2] = 1;
    cout<<solve(n);
}

