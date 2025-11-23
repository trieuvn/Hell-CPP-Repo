#include<bits/stdc++.h>

using namespace std;

const int MAX = 1e5+5;

int n,u,v;
vector<int> adj[MAX];
int c[MAX];
int incount[MAX];
int incount2[MAX];
int outmax[MAX];

void dfsin(int cur, int par){
	for (int v : adj[cur]){
		if (v == par)	continue;
		incount[cur]++;
		dfsin(v,cur);
		incount[cur] += incount[v];
	}
}

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for (int i=0;i<n-1;i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfsin(1,0);
	
	for (int i=1;i<=n;i++){
		cout<<incount[i]<<" ";
	}
}
