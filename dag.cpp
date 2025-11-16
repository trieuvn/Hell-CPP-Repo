#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1e5+5;
const int MOD = 1e9+7;

int n,m;
int vis[MAX];
vector<int> adj[MAX];
vector<int> topo_order;
bool has_cycle;

void dfs(int cur){
	vis[cur] = 1;
	for (int v : adj[cur]){
		if (vis[v] == 0){
			dfs(v);
		}else if (vis[v] == 1){
			has_cycle = true;
			//return ;
		}
	}
	vis[cur] = 2;
	topo_order.push_back(cur);
}

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	int u,v;
	for (int i=0;i<m;i++){
		cin>>u>>v;
		adj[u].push_back(v);
	}
	
	dfs(1);
	if (topo_order.size() < n){
		cout<<"NO";
	}else{
		cout<<"YES";
	}
}
