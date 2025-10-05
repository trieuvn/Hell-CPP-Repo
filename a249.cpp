#include<bits/stdc++.h>

using namespace std;
const int MAX = 1e5+5;

int c = 0;
vector<bool> vis;
vector<int> graph[MAX];
int Alice[MAX];
int n,m,k;
int min_path;

void bfsMarisa(int cur){
	queue<pair<int,int>> q;
	vis.assign(MAX+1,false);
	vis[cur] = true;
	q.push({cur,0});
	while(!q.empty()){
		cur = q.front().first;
		int cost = q.front().second;
		q.pop();
		if (cur == n){
			min_path = cost;
			return ;
		}
		for (int u : graph[cur]){
			if (vis[u] == false){
				vis[u] = true;
				q.push({u,cost+1});
			}
		}
	}
}

void bfsAlice(int dest){
	queue<pair<int,int>> q;
	vis.assign(MAX+1,false);
	vis[dest] = true;
	Alice[dest] = 0;
	q.push({dest,0});
	while(!q.empty()){
		int cur = q.front().first;
		int cost = q.front().second;
		Alice[cur] = cost;
		q.pop();
		for (int u : graph[cur]){
			if (vis[u] == false){
				vis[u] = true;
				q.push({u,cost+1});
			}
		}
	}
}

signed main(){
	cin>>n>>m>>k;
	int clone[k];
	for (int i=0;i<k;i++){
		cin>>clone[i];
	}
	for (int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	bfsMarisa(1);
	bfsAlice(n);
	int ans = 0;
	for (int i=0;i<k;i++){
		if (min_path >= Alice[clone[i]]) ans++;
	}
	cout<<ans;
}
