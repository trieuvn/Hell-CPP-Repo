#include<bits/stdc++.h>
#define int int64_t

using namespace std;

int n;
int a[15][15];
bool vis[15];

int solve(int start, int cur, int par){
	if (start == cur && vis[cur] == true){
		for (int i=0;i<n;i++){
			if (vis[i] == false)	return INT_MAX;
			//cout<<"HIHI";
		}
		//cout<<"HIH";
		return a[start][start];
	}
	int Min = INT_MAX;
	for (int i=0;i<n;i++){
		if (i == par || i == cur) continue;
		if (vis[i] == false){
			vis[i] = true;
			Min = min(Min, a[cur][i] + solve(start,i,cur));
			vis[i] = false;
			//cout<<"HIHI";
		}
	}
	//cout<<"HI";
	return Min;
}

signed main(){
	cin>>n;
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	int Min = INT_MAX;
	for (int i=0;i<n;i++){
		for (int i=0;i<n;i++)	vis[i] = false;
		Min = min(Min, a[i][i] + solve(i,i,-1));
		//cout<<"HIHI";
	}
	
	cout<<Min;
}
