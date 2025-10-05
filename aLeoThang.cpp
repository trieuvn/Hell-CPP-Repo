#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
	int n,m,i,j;
	cin>>n>>m;
	int a[m+1];
	int dp[n+1];
	for (i=0;i<m;i++){
		cin>>a[i];
	}
	a[m] = -1;
	j=0;
	dp[0] = 1;
	dp[1] = 1;
	if (a[0] == 2){
		dp[2] = 0;
		j++;
	}else{
		dp[2] =1;
	}
	
	for (i=3;i<=n;i++){
		if (i == a[j]){
			//cout<<"DSJDHS";
			dp[i] = 0;
			j++;
		
		}else{
			dp[i] = (dp[i-1] + dp[i-2])%2023;
		}
	}
	//for (i=0;i<=n;i++){
		//cout<<dp[i]<<" ";
	//}
	cout<<dp[n]%2023;
}
