#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 5005;

int n,m;

int a[5005];
int b[5005];

int dpdown[5005][MAX];
int dpup[5005][MAX];

int maxup[MAX][MAX];
int maxdown[MAX][MAX];

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=m;i++){
		cin>>b[i];
	}
	int Max = 0;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if (a[i] <= b[j]){
				dpdown[i][j] = maxup[i-1][j-1] + 1;
			}
			if (a[i] >= b[j]){
				dpup[i][j] = maxdown[i-1][j-1] + 1;
			}
			maxup[i][j] = max({maxup[i-1][j], maxup[i][j-1], dpup[i][j]});
			maxdown[i][j] = max({maxdown[i-1][j], maxdown[i][j-1], dpdown[i][j]});
		}
	}
	cout<<max(maxup);
}
