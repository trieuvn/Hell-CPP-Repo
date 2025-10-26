#include<bits/stdc++.h>
#define int long long

using namespace std;
const int MAX = 1e6+5;

int t,n;
map<int,int> dp;

int solve(int x){
	if (x == 1)	return 0;
	if (dp[x] != 0) return dp[x];
	if (x % 2 == 0){
		return dp[x] = 1+solve(x/2);
	}else{
		return dp[x] = 1+solve(3*x+1);
	}
}

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while (t--){
		cin>>n;
		cout<<solve(n)<<"\n";
	}
}
