#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 2*1e5+5;
const int MOD = 1e9+7;

int n,m;
vector<pair<int,int>> adj[MAX];
vector<int> shortest_path(MAX,LLONG_MAX);
bool vis[MAX];
int count[MAX];
vector<int> dp(MAX, -1);

void DS(){
	shortest_path[1] = 0;
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({0,1});
	int count = 0;
	while(!pq.empty()){
		int node = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if (cost > shortest_path[node])	continue;
		
		for (pair<int,int> v : adj[node]){
			int vnode = v.first;
			int vcost = v.second;
			if (cost + vcost < shortest_path[vnode]){
				shortest_path[vnode] = cost + vcost;
				pq.push({cost + vcost, vnode});
			}
		}
	}
}

int dfs(int u){
	if (u == 1){
		return 1;
	}
	
	if (dp[u] != -1){
		return dp[u];
	}
	
	int sum = 0;
	
	for (pair<int,int> v : adj[u]){
		int vnode = v.first;
		int vcost = v.second;
		if (shortest_path[vnode] != LLONG_MAX && shortest_path[vnode] + vcost == shortest_path[u]){
			sum = (sum + dfs(vnode))%MOD;
		}
	}
	return dp[u] = sum;
}

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	int u,v,w;
	for (int i=0;i<m;i++){
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	
	DS();
	
	cout<<dfs(n)%MOD;
}
