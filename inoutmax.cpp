#include<bits/stdc++.h>

using namespace std;

const int MAX = 1e5+5;

int n,u,v;
vector<int> adj[MAX];
int c[MAX];
int inmax[MAX];
int inmax2[MAX];
int outmax[MAX];

void dfsin(int cur, int par){
	inmax[cur] = 0;
	inmax2[cur] = 0;
	c[cur] = 0;
	
	for (int v : adj[cur]){
		if (v == par)	continue;
		dfsin(v,cur);
		int val = inmax[v] + 1;
		if (val > inmax[cur]){
			inmax2[cur] = inmax[cur];
			inmax[cur] = val;
			c[cur] = v;
		}else if (val > inmax2[cur]){
			inmax2[cur] = val;
		}
	}
}

void dfsout(int cur, int par){
	for (int v : adj[cur]){
		if (v == par)	continue;
		int longestfromu;
		if (c[cur] == v){
			longestfromu = max(outmax[cur], inmax2[cur]);
		}else{
			longestfromu = max(outmax[cur], inmax[cur]);
		}
		outmax[v] = longestfromu + 1;
		dfsout(v,cur);
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
	
	dfsout(1,0);
	
	for (int i=1;i<=n;i++){
		cout<<max(outmax[i],inmax[i])<<" ";
	}
}
