#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 2e5+5;

int n,x,q;
int a[MAX];
int diff[MAX];
int st[4*MAX];

int gcd(int a, int b){
	return (b == 0) ? a : __gcd(a,b);
}

void build(int id, int l, int r){
	if (l == r){
		st[id] = diff[l];
		return;
	}
	int m = (l+r)/2;
	build(2*id,l,m);
	build(2*id+1,m+1,r);
	st[id] = gcd(st[2*id], st[2*id+1]);
}

int query(int id, int tl, int tr, int l, int r){
	if (tl > r || tr < l){
		return 0;
	}
	if (tl >= l && tr <= r){
		return st[id];
	}
	
	int tm = (tr+tl)/2;
	int vl = query(2*id,tl,tm,l,r);
	int vr = query(2*id+1,tm+1,tr,l,r);
	return gcd(vl,vr);
}

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for (int i=1;i<n;i++){
		diff[i] = abs(a[i] - a[i+1]);
	}
	
	build(1,1,n);
	
	while (q--){
		int l,r;
		cin>>l>>r;
		int res = query(1,1,n,l,r-1);
		cout<<res<<"\n";
	}
}
