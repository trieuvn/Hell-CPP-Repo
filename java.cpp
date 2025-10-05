#include<bits/stdc++.h>
#define int long long
const int MAX = 500+5;

using namespace std;

int A[MAX][MAX];
int pre[MAX][MAX];

signed main(){
	int n,m;
	cin>>n>>m;
	
	int res = LLONG_MIN;
	
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			cin>>A[i][j];
			res = max(res, A[i][j]);
		}
	}
	
	for (int i=0;i<=n;i++){
		for (int j=0;j<=m;j++){
			pre[i][j] = 0;
		}
	}
	
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + A[i][j];
			res = max(res, pre[i][j]);
			for (int u=0;u<=i;u++){
				res = max(res, pre[i][j] - pre[i-u][j]);
			}
			for (int u=0;u<=j;u++){
				res = max(res, pre[i][j] - pre[i][j-u]);
			}
		}
	}
	cout<<res;
}
