#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	long n,i,j;
	cin>>n;
	vector<long> dp(n+1,0);
	dp[0] = 1;
	for (j=1;j<=n;j++)
	{
		for (i=1;i<=6;i++){
			if (j-i>=0){
				dp[j] = (dp[j] + dp[j-i])%1000000007;
			}
		}
	}
	cout<<dp[n];
}
