#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	long long f[10001];
	long i,j,k;
	f[1] = 1;
	f[2] =2;
	for (i=3;i<=10000;i++){
		f[i] = f[i-1] + f[i-2];
	}
	long T;
	cin>>T;
	long long m;
	for (k=0;k<T;k++){
		cin>>m;
		vector <long> dp(m+1,0);
		dp[0] = 1;
		for (i=1;f[i]<=100000000000000001;i++){
			for (j=m;j>=1;j--){
				if (j>=f[i]){
					dp[j] = dp[j] +dp[j-f[i]];
				}
			}
		}
		cout<<dp[m]<<"\n";
	}
	/*for (i=1;i<70;i++){
		cout<<f[i]<<"\n";
	}*/
}
