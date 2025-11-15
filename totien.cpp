#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1e5+5;

int n,q;
int tin[MAX];
int tout[MAX];
int timer;
vector<int>	adj[MAX];

void dfs(int cur, int par){
	tin[cur] = ++timer;
	for (int v : adj[cur]){
		if (v == par)	continue;
		dfs(v,cur);
	}
	tout[cur] = timer;
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
	
	dfs(1,0);
	
	for (int i=0;i<q;i++){
		cin>>u>>v;
		if (tin[u] < tin[v] && tout[u] >= tin[v]){
			cout<<"MA\n";
		}
		else if (tin[v] < tin[u] && tout[v] >= tin[u]){
			cout<<"RI\n";
		}else{
			cout<<"SA\n";
		}
	}
}

