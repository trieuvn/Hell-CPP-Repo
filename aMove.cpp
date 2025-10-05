#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int k,n,i,j;
	cin>>n>>k;
	long a[n+1];
	for (i=0;i<n;i++){
		cin>>a[i];
	}
	vector<long> dp(k+1,0);
	dp[0] = 1;
	for (i=0;i<n;i++){
		for (j=k;j>=1;j--){
			dp[j] = (dp[j] + dp[j-1]*a[i])%1000000007;
		}
	}
	cout<<dp[k];
}
