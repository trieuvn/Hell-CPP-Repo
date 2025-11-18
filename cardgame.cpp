#include<bits/stdc++.h>
#define int int64_t

using namespace std;

const int MAX = 2e6+5;

int n;

int a[MAX];
int st[10*MAX];
int prefix[MAX];

void build(int id, int l, int r){
	if (l == r){
		st[id] = a[l];
		return;
	}
	int m = (l+r)/2;
	build(2*id,l,m);
	build(2*id+1,m+1,r);
	
	st[id] = max(st[2*id], st[2*id+1]); 
	return ;
}

int get(int id, int tl, int tr, int l, int r){
	if (tr < l || tl > r){
		return LLONG_MIN;
	}
	if (l <= tl && tr <= r){
		return st[id];
	}
	
	int tm = (tl+tr)/2;
	int vl = get(2*id,tl,tm,l,r);
	int vr = get(2*id+1,tm+1,tr,l,r);
	
	return max(vl,vr);
}

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		prefix[i] = prefix[i-1] + a[i];
	}
	
	build(1,1,n);
	
	int mn = 0;
	int mxpoint = 0;
	for (int i=1;i<=n;i++){
		int p = 0;
		for (int j=1;j<i;j++){
			int maxval = get(1,1,n,j,i);
			if (maxval == LLONG_MIN) continue;
			int sum = prefix[i] - prefix[j-1];
			p = sum - maxval;
			mxpoint = max(mxpoint, p);
		}
	}
	cout<<mxpoint;
}
