#include<bits/stdc++.h>

using namespace std;

const int MAX = 1e5+5;

int n,m;
int a[105];
bool dp[MAX];

signed main(){
	cin>>n>>m;
	for (int i=0;i<m;i++){
		cin>>a[i];
	}
	dp[0] = false;
	for (int i=1;i<=n;i++){
		dp[i] = false;
		for (int j=0;j<m;j++){
			if (i - a[j] >= 0){
				if (dp[i - a[j]] == false){
					dp[i] = true;
					break;
				}
			}
		}
	}
	if (dp[n] == true){
		cout<<"Marisa";
	}else{
		cout<<"Reimu";
	}
}
