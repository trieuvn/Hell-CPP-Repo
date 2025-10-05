#include<bits/stdc++.h>
#define int long long

using namespace std;


vector<int> adj[101];
vector <vector<int>> dp(101,vector<int>(101,0));
int apple[101][101];

int solve(int cur, int prev, int q){
	if (q == 0){
		dp[cur][q] = 0;
		return 0;
	}
	if (adj[cur].size() < 2){
		dp[cur][q] = 0;
		return 0;
	}	
	//if (dp[cur][q] != -1) return dp[cur][q];
	int res = 0;
	for (int u : adj[cur]){
		if (u == prev) continue;
		for (int v : adj[cur]){
			if (v == prev)	continue;
			for (int k = 0;k<=q;k++){
				int x=0;
				if (k!=0)
					x += apple[cur][u] + solve(u,cur,k-1);
				if (k!=q)
					x += apple[cur][v] + solve(v,cur,q-k-1);
				res = max(res, x);
				/*res = max(res, 
							k==0?0:apple[cur][u] + solve(u,cur,k-1)
							+ k==q?0:apple[cur][v] + solve(v,cur,q-k-1));*/
			}
		}
	}
	dp[cur][q] =res;
	return res; 
}

signed main(){
	int n,q,i,j,x,y,t;
	cin>>n>>q;
	for (i=0;i<n-1;i++){
		cin>>x>>y>>t;
		adj[x].push_back(y);
		adj[y].push_back(x);
		apple[x][y] = t;
		apple[y][x] = t;
	}
	cout<<solve(1,-1,q);
}

