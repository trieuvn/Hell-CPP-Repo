#include<bits/stdc++.h>

using namespace std;

int main(){
	long n,i,j;
	cin>>n;
	long a[n+1];
	vector<long> lis;
	vector<long> v(n+1,-1);
	long Max =0;
	for (i=0;i<n;i++){
		cin>>a[i];
	}
	vector<long> dp(n+1,1);
	for (i=1;i<n;i++){
		for (j=0;j<i;j++){
			if (a[i] > a[j]){
				if (dp[i] < dp[j]+1){
					dp[i] = dp[j]+1;
					if (dp[Max] < dp[i]){
						Max= i;
					}
					//cout<<j<<" ";
					v[i] = j;
				}
								
			}
		}
		
	
	}
	cout<<dp[Max]<<"\n";
	for (i=Max;i!=-1;i=v[i]){
		lis.push_back(i+1);
	}
	reverse(lis.begin(),lis.end());
	for (long k : lis){
		cout<<k<<" ";
	}
}
