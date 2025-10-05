#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1e5+5;

int n, m;
vector<int> adj[MAX];
vector<int> adjr[MAX];
bool visited[MAX];
stack<int> TG;

void reset(){
	for (int i=0;i<=MAX;i++){
		visited[i] = false;
	}
}

void dfsG(int par, int cur){
	if (visited[cur] == true){
		return;
	}
	visited[cur] = true;
	for (int u : adj[cur]){
		if (u == par)	continue;
		dfsG(cur, u);
	}
	TG.push(cur);
}

void dfsTG(int par, int cur){
	if (visited[cur] == true){
		return;
	}
	//cout<<cur<<" ";
	visited[cur] = true;
	for (int u : adjr[cur]){
		if (u == par)	continue;
		//cout<<u<<" ";
		dfsTG(cur, u);
	}
}

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	int v,e;
	for (int i=0;i<m;i++){
		cin>>v>>e;
		adj[v].push_back(e);
		adjr[e].push_back(v);
	}
	for (int i=1;i<=n;i++){
		if (!visited[i]){
			dfsG(-1,i);
		}
	}
	reset();
	int s = 0;
	while (!TG.empty()){
		int u = TG.top();
		TG.pop();
		//cout<<u<<" ";
		if (visited[u] == true)	continue;
		//cout<<u<<" ";
		//cout<<"\n";
		dfsTG(-1, u);
		s++;
	}
	cout<<s;
	
}
