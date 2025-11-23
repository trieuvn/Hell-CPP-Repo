#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1e5+5;

int n,p;

int a[MAX];
vector<int> adj[MAX];
int parent[MAX];
int sz[MAX];
set<int> mau[MAX];
int ans[MAX];

int find(int u){
	if (parent[u] == u)	return u;
	return parent[u] = find(parent[u]);
}

void unite(int u, int v){
	u = find(u);
	v = find(v);
	if (u != v){
		if (mau[u].size() > mau[v].size())	swap(u,v);
		parent[u] = v;
		
		for (int c : mau[u]){
			mau[v].insert(c);
		}
	}
}

void dfs(int cur, int par){
	for (int v : adj[cur]){
		if (v == par)	continue;
		dfs(v,cur);
		unite(cur, v);
	}
	
	ans[cur] = mau[find(cur)].size();
}

signed main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		mau[i].insert(a[i]);
		parent[i] = i;
	}
	
	int u,v;
	for (int i=0;i<n-1;i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs(1,0);
	
	for (int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
}
