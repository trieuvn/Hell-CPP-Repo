#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1e5+5;
const int LOGN = 20;

int n,q;
vector<pair<int,int>> adj[MAX];
int h[MAX];
int up[MAX][LOGN+5];
int d[MAX];

void dfs(int u, int par, int c){
	h[u] = h[par] + 1;
	up[u][0] = par;
	d[u] = c;
	for (pair<int,int> v : adj[u]){
		int node = v.first;
		int cost = v.second;
		if (node == par)	continue;
		dfs(node,u,c+cost);
	}
}

void preprocess(){
	h[0] = 0;
	up[1][0] = 0;
	
	dfs(1,0,0);
	
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
	cin>>n>>q;
	int u,v,w;
	for (int i=0;i<n-1;i++){
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	
	preprocess();
	
	for (int i=0;i<q;i++){
		cin>>u>>v;
		cout<<d[u] + d[v] - 2*d[lca(u,v)]<<"\n";
	}
}
