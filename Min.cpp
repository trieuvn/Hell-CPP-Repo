#include<bits/stdc++.h>
#define int long long

using namespace std;

int n,m;

int a[25][25];
int k[25][25];

bool check(){
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if (a[i][j] != 0)	return false;
		}
	}
	return true;
}

bool Dat(int d, int c, int t){
	if (d >= n+1){		
		if(check())	return true;
		return false;
	}
	
	if (t == 1){
		a[d][c-1]--;
		a[d][c+1]--;
		a[d-1][c]--;
		a[d-1][c-1]--;
		a[d-1][c+1]--;
		a[d+1][c]--;
		a[d+1][c-1]--;
		a[d+1][c+1]--;
		
	}
	
	bool res = false;
	
	if (c == m){
		res = Dat(d+1,1,1);
	}else{
		res = Dat(d,c+1,1);
	}
	
	if (res == true){
		k[d][c] = t;
		return true;
	}
	
	if (res == false && t == 1){
		a[d][c-1]++;
		a[d][c+1]++;
		a[d-1][c]++;
		a[d-1][c-1]++;
		a[d-1][c+1]++;
		a[d+1][c]++;
		a[d+1][c-1]++;
		a[d+1][c+1]++;
		res = Dat(d,c,0);
		if (res == true){
			k[d][c] = 0;
			return true;
		}
	}
	return false;
}

signed main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	
	bool res = Dat(1,1,1);
	
	if (res == true){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
				cout<<k[i][j]<<" ";
			}
			cout<<"\n";
		}
		return 0;
	}
	
	Dat(1,1,0);
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			cout<<k[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
