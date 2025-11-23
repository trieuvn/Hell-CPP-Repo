#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1e6+5;
const int MOD = 1e9+7;

int n,m;
vector<int> adj[MAX];
int c[MAX];
int in_degree[MAX];
vector<int> topo;
int dpin[MAX];
int dpout[MAX];

void kahn(){
	for (int i=1;i<=n;i++){
		for (int v : adj[i]){
			in_degree[v]++;
		}
	}
	
	queue<int> q;
	for (int i=1;i<=n;i++){
		if (in_degree[i] == 0){
			q.push(i);
			//topo.push_back(i);
		}
	}
	
	while(!q.empty()){
		int u = q.front();
		q.pop();
		topo.push_back(u);
		
		for (int v : adj[u]){
			in_degree[v]--;
			if (in_degree[v] == 0){
				q.push(v);
			}
		}
	}
}

signed main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>c[i];
		dpin[i] = 1;
		dpout[i] = 1;
	}
	
	int u,v;
	for (int i=0;i<m;i++){
		cin>>u>>v;
		adj[u].push_back(v);
	}
	
	kahn();
	
	if (topo.size() < n){
		cout<<"-1";
		return 0;
	}
	
	for (int u : topo){
		for (int v : adj[u]){
			dpin[v] = (dpin[v] + dpin[u])%MOD;
		}
	}
	
	for (int i=n-1;i>=0;i--){
		int u = topo[i];
		for (int v : adj[u]){
			dpout[u] = (dpout[u] + dpout[v])%MOD;
		}
	}
	
	int ans = 0;
	
	for (int i=1;i<=n;i++){
		int dp = (dpin[i] * dpout[i])%MOD;
		ans = (ans + (dp * c[i])%MOD)%MOD;
	}
	
	cout<<ans;
	1<<
	>>
	& 
	^
	|
	~
	000001 = 1 & 1<<4 001000 = 0
	000000 = 0 3-1 = 000100 1<<3 
	000001 = 1 1<<k 
	1 = 000001 1<<2 = 000100
	123 -> 101010100 -> mon hang thu 1 toi ko lay, mon hang thu 3 toi lay
	dp[123]
	1 3 -> 000100
	2 6 -> 100100
	2*x = 1<<x
}
