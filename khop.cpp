#include<bits/stdc++.h>

using namespace std;

const int MAX = 1e5+5;

int n,m;
vector<int> adj[MAX];
bool iskhop[MAX];
int cau;
int low[MAX];
int num[MAX];
int timer;
vector<int> khoplist;

void dfs(int u, int p){
	num[u] = low[u] = ++timer;
	int child = 0;
	bool skip = false;
	for (int v : adj[u]){
		if (v == p && !skip){
			skip = true;
			continue;
		}	
		if (num[v]){
			low[u] = min(low[u], num[v]);
		}else{
			child++;
			dfs(v,u);
			low[u] = min(low[v], low[u]);
			
			if (low[v] > num[u]){
				cau++;
			}
			
			if (u != p && low[v] >= num[u]){
				iskhop[u] = true;
			}
		}
	}
	if (u == p && child > 1){
		iskhop[u] = true;
	}
}

signed main(){
	cin>>n>>m;
	int u,v;
	for (int i=0;i<m;i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	for (int i=1;i<=n;i++){
		if (num[i]==0)
			dfs(i,i);
	}
	int count = 0;
	for (int i=1;i<=n;i++){
		if (iskhop[i]){
			count++;
		}
	}
	
	cout<<count<<" "<<cau;
	
}
