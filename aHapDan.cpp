#include<bits/stdc++.h>

const int sl = 1e5+5;

using namespace std;
int dp[sl];
int snt[sl];

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int p;
	char s[sl];
	cin>>p;
	cin>>s;
	int n;
	cin>>n;
	int len = strlen(s);
	for (int i=1;i<=len;i++){
		if ((s[i-1] - '0')%p==0){
			dp[i] = dp[i-1] + i;
			snt[i] = snt[i-1] + 1;
		}else{
			dp[i] = dp[i-1];
			snt[i] = snt[i-1];
		}
	}
	for (int i=0;i<n;i++){
		int l, r;
		cin>>l>>r;
		cout<<dp[r] - dp[l-1] - (l-1)*(snt[r] - snt[l-1])<<"\n";
	}
}
