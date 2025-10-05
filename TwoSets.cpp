#include<bits/stdc++.h>

using namespace std;
const long MOD = 1000000007;

int main(){
	long long n,i,j;
	cin>>n;	
	long long out=1;
	for (i=2;i<=n;i++)	out+=i;
	if (out%2!=0){
		cout<<"0";
		return 0;
	}
	vector<long long> dp(out/2+1,0);
	
	dp[0] = 1;
	for (i=1;i<=n;i++){
		for (j=out/2;j>=1;j--){
			if (j>=i){
				dp[j] = (dp[j]%MOD + dp[j-i]%MOD);
				//cout<<dp[j]<<"\n";
			}
		}
	}
	//cout<<"out:"<<out<<"\n";
	cout<<(dp[out/2]/2)%MOD;
}
