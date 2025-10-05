#include<bits/stdc++.h>
#define int long long

using namespace std;

const int M = 1e9+7;
const int SL = 1e5+5;

int u,v,n;
vector<int> graph[SL];
int dp[SL];
bool vis[SL];

int dfs(int cur){
	vis[cur] = true;
	dp[cur] = 1;
	for (int u : graph[cur]){
		if (vis[u]==false){
			dp[cur] = (dp[cur] * (dfs(u)+1)%M)%M;
		}
	}
	return dp[cur];
}

signed main(){
	cin>>n;
	for (int i=1;i<n;i++){
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	dfs(1);
	int s = 0;
	for (int i=1;i<=n;i++){
		s = (s + dp[i])%M;
	}
	cout<<s%M;
}
