#include<bits/stdc++.h>
#define int int64_t

using namespace std;

const int MAX = 1e5+5;
const int INF = 1e18;
const int MOD = 1e9+7;

int n,k,q,t,m;
int p[MAX];
vector<int> adj[MAX];
bool vis[MAX];
int point;
int start;

void reset(){
	for (int i=0;i<MAX;i++){
		vis[i] = false;
	}
}

bool dfs(int cur){
	bool pos = false;
	int child = 0;
	for (int v : adj[cur]){
		child++;
		if (point >= p[v] && vis[v] == false){
			vis[v] = true;
			child--;
			point += p[v];
			dfs(v);
		}
	}
	int prevc = child;
	while (prevc != child && child != 0){
		for (int v : adj[cur]){
			if (point >= p[v] && vis[v] == false){
				vis[v] = true;
				child--;
				point += p[v];
				dfs(v);
			}
		}
	}
	if (cur == start){
		//cout<<"cur "<<start<<" ";
		for (int i=1;i<=n;i++){
			if (vis[i] == false){
				return false;
			}
		}
		return true;
	}
}

int BS(){
	int l = 0;
	int r = MAX-5;
	int m = (l+r)/2;
	int best = r;
	while(l<=r){
		point = m + p[start];
		reset();
		vis[start] = true;
		bool res = dfs(start);
		if (res == true){
			r = m-1;
			best = min(m,best);
		}else{
			l = m+1;
		}
		m = (l+r)/2;
		//cout<<m<" ";
	}
	return best;
}

int solve(){
	for (int i=0;i<MAX;i++){
		adj[i].clear();
	}
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>p[i];
	}
	
	for (int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	int sum = 0;
	for (int i=1;i<=n;i++){
		start = i;
		sum += BS();
		
	}
	return sum;
}

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while (t--){
		cout<<solve()<<"\n";
	}
}
