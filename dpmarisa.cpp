#include<bits/stdc++.h>
#define int long long

using namespace std;

int n;
int a[505];
int temp[505];
int dp[505];

int resetDP(){
	for (int i=0;i<505;i++){
		dp[i] = 0;
	}
	int VTMin = 0;
	for (int i=1;i<n;i++){
		dp[i-1] = a[i-1] + a[i];
		if (dp[VTMin] > dp[i-1]){
			VTMin = i-1;
		}
	}
	return VTMin;
}

signed main(){
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	int vtdpmin = resetDP();
	int s = dp[vtdpmin];
	while (n>1){
		int j = 0;
		for (int i=0;i<n;i++){
			if (i==vtdpmin){
				temp[j] = dp[vtdpmin];
				i++;
				j++;
				continue;
			}
			temp[j] = a[i];
			j++;
		}
		n--;
		for (int i=0;i<n;i++){
			a[i] = temp[i];
			//cout<<a[i]<<" ";
		}
		//cout<<"\n";
		vtdpmin = resetDP();
		s += dp[vtdpmin];
	}
	cout<<s;
}
