#include<bits/stdc++.h>

using namespace std;

int main(){
	long long n,i,j;
	cin>>n;
	long long a[n+1];
	long long w[n+1];
	unsigned long long dpw[n+1];
	vector<long long> v(n+1,-1);
	long long Max = 0;
	for (i=0;i<n;i++){
		cin>>a[i];
	}
	for (i=0;i<n;i++){
		cin>>w[i];
	}

	dpw[0] = w[0];
	vector<long long> dp(n+1,1);
	for (i=1;i<n;i++){
		dpw[i] = w[i];
		for (j=0;j<i;j++){
			if (a[i] > a[j]){
				if (dp[i] < dp[j]+1){
					dp[i] = dp[j]+1;
					
					//cout<<j<<" ";

				}
				dpw[i] = max(w[i] + dpw[j],dpw[i]);			
			}
		}
		
		if (dpw[Max] < dpw[i]){
			Max = i;
		}
		
	
	}
	//cout<<Max<<"\n";
	cout<<dp[Max];
	v[dp[Max]] = Max;
	cout<<"\n";
	for (i=Max;i>=0;i--){
		//cout<<i;
		if (v[dp[i]] == -1 || (a[i] < a[v[dp[i]]+1] && dpw[i]>=dpw[v[dp[i]]])){
			//cout<<"DSHDS";
				v[dp[i]] = i;
			
		
		}
	}
	cout<<"\n";
	for (i=0;i<n;i++)	cout<<dpw[i]<<" ";
	cout<<"\n";
	for (i=1;i<=dp[Max];i++){
		if (v[i] == -1 )	break;
		cout<<v[i]+1<<" ";
	}
}

