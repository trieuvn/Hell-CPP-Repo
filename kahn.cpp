#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1e5+5;
const int MOD = 1e9+7;

int n,m;

vector<int> adj[MAX];
vector<int> topo_order;
int in_degree[MAX];
int dp[MAX];
int Max;

void kahn(){
	queue<int> q;
	for (int i=1;i<=n;i++){
		in_degree[i] = 0;
		dp[i] = 0;
	}
	
	for (int i=1;i<=n;i++){
		for (int v : adj[i]){
			in_degree[v]++;
		}
	}
	
	queue<int> pq;
	for (int i=1;i<=n;i++){
		if (in_degree[i] == 0){
			q.push(i);
			dp[i] = 1;
		}
	}
	
	while(!q.empty()){
		int node = q.front();
		q.pop();
		Max = max(dp[node], Max);
		topo_order.push_back(node);
		
		for (int v : adj[node]){
			in_degree[v]--;
			
			dp[v] = max(dp[v], dp[node] + 1);
			
			if (in_degree[v] == 0){
				q.push(v);
			}
		}
	}
}

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	int u,v;
	for (int i=0;i<m;i++){
		cin>>u>>v;
		adj[u].push_back(v);
	}
	
	kahn();
	cout<<Max;
}
