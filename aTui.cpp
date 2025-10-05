#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
	int n,m,i,j;
	cin>>n>>m;
	int v[n+1],w[n+1];
	vector<int> dp(m+1,0);
	vector<int>	trace(n+1,-1);
	vector<int> prev(m+1,-1);
	vector<int> lis;
	for (i=0;i<n;i++){
		cin>>v[i]>>w[i];
	}
	int maxindex = 0;
	for (i=0;i<n;i++){
		for (j=m;j>=0;j--){
			if (j-w[i] >= 0){
				if (dp[j-w[i]] + v[i] > dp[j]){
					dp[j] = dp[j-w[i]] + v[i];
					prev[j] = i;
					if (j == m){
						trace[i] = prev[j-w[i]];
						maxindex = i;
					}
				}
				
			}
		}
	}
	cout<<dp[m];
	cout<<"\n";
	for (i=maxindex;i!=-1;i=trace[i]){
		lis.push_back(i+1);
	}
	reverse(lis.begin(),lis.end());
	for (int k : lis){
		cout<<k<<" ";
	}
}
