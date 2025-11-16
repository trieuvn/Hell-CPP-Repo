#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1e5;
const int LOGN = 20;

int n,q,k;
vector<int> adj[MAX+5];
int timer;
int tin[MAX+5], tout[MAX+5];

void dfs(int cur, int par){
	tin[cur] = ++timer;
	for (int v : adj[cur]){
		if (v != par){
			dfs(v,cur);
		}
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
	dfs(1,-1);
	tin[n+1]= ++timer;
	while (q--){
		cin>>k;
		int mn = n+1,mx = 0;
		for (int i=0;i<k;i++){
			cin>>u;
			if (tin[u] >= tin[mx]){
				mx = u;
			}
			if (tin[u] <= tin[mn]){
				mn = u;
			}
		}
		cout<<mn<<" "<<mx<<"\n";
	}
}
