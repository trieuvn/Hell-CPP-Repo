#include<bits/stdc++.h>
#define int long long

using namespace std;

typedef struct Node{
	int u;
	int v;
	int w;
}Node;

const int MAX = 1e5+5;

int n,p;
int cmin = LLONG_MAX;
int c[MAX];
Node canh[MAX];
int parent[MAX];
int sz[MAX];

bool cmp(Node a, Node b){
	int nwa = 2*a.w + c[a.u] + c[a.v];
	int nwb = 2*b.w + c[b.u] + c[b.v];
	
	if (nwa != nwb)	return nwa < nwb;
	return a.w < b.w;
}

int find(int u){
	if (parent[u] == u)	return u;
	return parent[u] = find(parent[u]);
}

void unite(int u, int v){
	u = find(u);
	v = find(v);
	if (u != v){
		if (sz[u] > sz[v])	swap(u,v);
		parent[u] = v;
		sz[v] += sz[u];
	}
}

signed main(){
	cin>>n>>p;
	for (int i=1;i<=n;i++){
		parent[i] = i;
		sz[i] = 1;
		cin>>c[i];
		cmin = min(cmin,c[i]);
	}
	
	int u,v,w;
	for (int i=0;i<p;i++){
		cin>>canh[i].u>>canh[i].v>>canh[i].w;
	}
	
	sort(canh,canh+p,cmp);
	int sum = 0;
	for (int i=0;i<p;i++){
		u = canh[i].u;
		v = canh[i].v;
		w = canh[i].w;
		int paru = find(u);
		int parv = find(v);
		if (paru != parv){
			unite(paru, parv);
			sum += 2*w + c[u] + c[v];
		}
	}
	
	cout<<sum+cmin;
}
