#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
	int n,m,i,j;
	cin>>n>>m;
	int a[n+1][m+1];
	int prefix[n+1][m+1];
	for (i=0;i<=m;i++) prefix[0][i] = 0;
	
	for (i=1;i<=n;i++){
		for (j=1;j<=m;j++){
			cin>>a[i][j];
			if (a[i][j] == pow(sqrt(a[i][j]),2)){
				prefix[i][j] = prefix[i-1][j] + 1; 
			}else{
				prefix[i][j] = prefix[i-1][j];
			}
		}
	}
	
	for (i=2;i<=n;i++){
		for (j=1;j<i;j++){
			
		}
	}
	
	for (i=1;i<=n;i++){
		for (j=1;j<=m;j++){
			cout<<prefix[i][j]<<" ";
		}
		cout<<"\n";
	}
}
