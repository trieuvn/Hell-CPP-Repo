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

void unionset(int v, int u){
	int paru = find(u);
	int parv = find(v);
	
	if (paru != parv){
	
		parent[paru] = parv;
		
	}
}

signed main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		parent[i] = i;
		sz[i] = 1;
	}
	int car;
	for (int i=0;i<n;i++){
		cin>>car;
		car = find(car);
		int nextcar = car%n + 1;
		unionset(nextcar,car);
		cout<<car<<" ";
	}
}
