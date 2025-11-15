#include<bits/stdc++.h>
#define int int64_t

using namespace std;

const int MAX = 1e6+5;
const int LOGN = 25; 

int n,q;
vector<pair<int,int>> adj[MAX];
int up[MAX][LOGN+5];
int h[MAX];
int upWeightMax[MAX][LOGN+5];

void dfs(int cur, int par, int vtocur){
	h[cur] = h[par] + 1;
	up[cur][0] = par;
	upWeightMax[cur][0] = vtocur;
	for (pair<int,int> v : adj[cur]){
		if (v.first == par)	continue;
		//cout<<v.first<<" "<<v.second<<"\n";
		dfs(v.first,cur,v.second);
	}
}

void build_lca(){
	up[1][0] = 0;
	upWeightMax[1][0] = 0;
	h[0] = 0;
	dfs(1,0,0);
	
	for (int i=1;i<=LOGN;i++){
		for (int u=1;u<=n;u++){
			up[u][i] = up[up[u][i-1]][i-1];
			upWeightMax[u][i] = max(upWeightMax[u][i-1], upWeightMax[up[u][i-1]][i-1]);
		}
	}
}

int lca(int u, int v){
	if (h[u] < h[v]){
		swap(u,v);
	}
	int Max = LLONG_MIN;
	int range = h[u] - h[v];
	
	for (int i=LOGN;i>=0;i--){
		if (((1<<i)&range) != 0){
			Max = max(Max, upWeightMax[u][i]);
			u = up[u][i];
		}
	}
	
	if (u == v){
		//cout<<"bababoi";
		return Max;
	}
	for (int i=LOGN;i>=0;i--){
		if (up[u][i] != 0 && up[u][i] != up[v][i]){
			Max = max(Max, upWeightMax[u][i]);
			Max = max(Max, upWeightMax[v][i]);
			u = up[u][i];
			v = up[v][i];
		}
	}
	Max = max(Max, upWeightMax[u][0]);
	Max = max(Max, upWeightMax[v][0]);
	return Max;
}

signed main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>q;
    int u,v,w;
    for (int i=0;i<n-1;i++){
    	cin>>u>>v>>w;
    	adj[u].push_back({v,w});
    	adj[v].push_back({u,w});
	}
	build_lca();
	
	for (int i=0;i<q;i++){
		cin>>u>>v;
		cout<<lca(u,v)<<"\n";
	}
	//cout<<"GIA TRI LA"<<upWeightMax[2][0];
}
