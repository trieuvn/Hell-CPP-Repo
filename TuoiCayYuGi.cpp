#include<bits/stdc++.h>

#define int long

using namespace std;

const int SL = 1e5+5;

vector<int> adj[SL];

bool vis[SL][SL];

int bfs(int a, int b){
	queue<pair<pair<int,int>, int>> q;
	q.push({{a,b},0});
	vis[a][b] = true;
	while (!q.empty()){
		int cura = q.front().first.first;
		int curb = q.front().first.second;
		int cur = q.front().second;
		q.pop();
		if (cura == curb)	return cur;
		for (int ka : adj[cura]){
			for (int kb : adj[curb]){
				if (vis[ka][kb] == true) continue;
				vis[ka][kb] = true;
				q.push({{ka,kb},cur+1});
			}
		}
	}
	return -1;
}

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,a,b;
	cin>>n>>m;
	cin>>a>>b;
	for (int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cout<<bfs(a,b);
}
