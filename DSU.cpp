#include<bits/stdc++.h>
#define int long long

using namespace std;
const int MAX = 1e5+5;

int n,q;
int parent[MAX];
int sz[MAX];

int find(int u){
	if (parent[u] == u)	return u;
	
	return find(parent[u]);
}

void unionset(int u, int v){
	int paru = find(u);
	int parv = find(v);
	
	if (paru != parv){
		if (sz[paru] > sz[parv])	swap(paru,parv);
	
		parent[paru] = parv;
		
		sz[parv] += sz[paru];
	}
}

signed main(){
	cin>>n>>q;
	for (int i=1;i<=n;i++){
		parent[i] = i;
		sz[i] = 1;
	}
	for (int i=0;i<q;i++){
		int id,u,v;
		cin>>id>>u>>v;
		if (id == 1){
			unionset(u,v);
		}else{
			if (find(u) == find(v)){
				cout<<"YES\n";
			}else{
				cout<<"NO\n";
			}
		}
	}
}
