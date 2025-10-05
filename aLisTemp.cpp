#include<bits/stdc++.h>

using namespace std;

int main(){
	long long n,i,j;
	cin>>n;
	long long a[n+1];
	long long w[n+1];
	long long dpw[n+1];
	vector<long long> v(n+1,-1);
	long long Max = 0;
	for (i=0;i<n;i++){
		cin>>a[i];
	}
	for (i=0;i<n;i++){
		cin>>w[i];
	}
	vector <long long> res;
	dpw[0] = w[0];
	vector<long long> dp(n+1,1);
	for (i=1;i<n;i++){
		dpw[i] = w[i];
		for (j=0;j<i;j++){
			if (a[i] > a[j]){
				if (dp[i] < dp[j]+1){
					dp[i] = dp[j]+1;
					v[i] = j;			
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

	cout<<"\n";
	for (i= Max;i!=-1;i=v[i]){
		res.push_back(i+1);
	}
	
	//cout<<"\n";
	//for (i=0;i<n;i++)	cout<<dpw[i]<<" ";
	//cout<<"\n";
	reverse(res.begin(),res.end());
	for (long long k : res){
		cout<<k<<" ";
	}
}
