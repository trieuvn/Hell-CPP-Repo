#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1e5;
const int LOGN = 20;

int n,q,k;
vector<int> adj[MAX+5];
int up[MAX+5][LOGN+5];
int h[MAX+5];

void dfs(int cur, int par){
	h[cur] = h[par] + 1;
	up[cur][0] = par;
	
	for (int v : adj[cur]){
		if (v == par)	continue;
		dfs(v,cur);
	}
}

void build_lift(){
	up[1][0] = 0;
	h[0] = 0;
	
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
		if (((1<<i)&range) != 0){
			u = up[u][i];
		}
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
	build_lift();
	while (q--){
		cin>>k;
		int a[2*MAX+5];
		for (int i=0;i<k;i++){
			cin>>a[i];
		}
		int best = lca(a[0],a[1]);
		pair<int,int> res = {a[0],a[1]};
		
		int j = 0;
		
		for (int i=2;i<k;i++){
			int newlca = lca(a[i],a[j]);
			while (j<i && h[newlca] < h[best]){
				best = newlca;
				res = {a[i],a[j]};
				j++;
				newlca = lca(a[i],a[j]);
			}
		}
		cout<<res.first<<" "<<res.second<<"\n";
	}
}
