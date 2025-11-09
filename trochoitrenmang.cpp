#include<bits/stdc++.h>

using namespace std;

const int MAX = 5*1e3+5;

int n,m;
int a[MAX];
bool dp[MAX][MAX];

int solve(int l, int r, bool wh){
	if (wh == true){
		int ch1 = a[l] + solve(l+1,r)
	}
}

signed main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<solve(1,n,true);
}
