#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1e5+5;
const int LOGN = 20;

int n,q;
vector<int> adj[MAX];
int h[MAX];
int up[MAX][LOGN+5];

void dfs(int cur, int par){
	h[cur] = h[par] + 1;
	up[cur][0] = par;
	for (int u : adj[cur]){
		if (u == par)	continue;
		dfs(u, cur);
	}
}

void preprocess(){
	h[0] = 0;
	up[1][0] = 0;
	dfs(1,0);
	
	for (int i=1;i<=LOGN;i++){
		for (int u=1;u<=n;u++){
			up[u][i] = up[up[u][i-1]][i-1];
		}
	}
}

int lca(int u, int v){
	if (h[u] < h[v]){
		swap(u,v);
	}
	
	int range = h[u] - h[v];
	
	for (int i=LOGN;i>=0;i--){
		if (((1<<i)&range) == 0)	continue;
		u = up[u][i];
	}
	
	if (u == v){
		return u;
	}
	
	for (int i=LOGN;i>=0;i--){
		if (up[u][i] != 0 && up[u][i] != up[v][i]){
			u = up[u][i];
			v = up[v][i];
		}
	}
	
	return up[u][0];
}

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	int u,v;
	for (int i=0;i<n-1;i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	preprocess();
	
	for (int i=0;i<q;i++){
		cin>>u>>v;
		cout<<lca(u,v)<<" ";
	}
}
