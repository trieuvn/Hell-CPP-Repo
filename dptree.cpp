#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1e5+5;
const int MOD = 1e9+7;

int n,u,v;
vector<int> adj[MAX];
int dptr[MAX][2];

void dfs(int cur, int par){
	dptr[cur][0] = 1;
	dptr[cur][1] = 1;
	for (int v : adj[cur]){
		if (v == par)	continue;
		dfs(v,cur);
		dptr[cur][0] = (dptr[cur][0] * dptr[v][1])%MOD;
		dptr[cur][1] = (dptr[cur][1] * (dptr[v][0] + dptr[v][1])%MOD)%MOD;
	}
}

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	cin>>n;
	for (int i=0;i<n-1;i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs(1,0);
	
	cout<<(dptr[1][0] + dptr[1][1])%MOD;
}
