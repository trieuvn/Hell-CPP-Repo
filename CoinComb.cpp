#include<bits/stdc++.h>
#define MODULO 1000000007;

using namespace std;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	long n,i;
	long long x;
	long long sum = 0;
	cin>>n>>x;
	long long a[n+1];
	for (i=0;i<n;i++){
		cin>>a[i];
	}
	long long dp[x+1];
	fill(dp,dp+x+1,0);
	dp[0] = 1;
	for (i=0;i<n;i++){
		for (long j=1;j<=x;j++){
			if (j-a[i] >= 0){
				dp[j] += dp[j-a[i]];
				dp[j]%=1000000007;
			
			}
		}
	}
	cout<<dp[x];
}
