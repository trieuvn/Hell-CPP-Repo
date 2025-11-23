#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 2e5+5;

int n,x,q;
int a[MAX];
int st[4*MAX];

void build(int id, int l, int r){
	if (l == r){
		st[id] = a[l];
		return;
	}
	int m = (l+r)/2;
	build(2*id,l,m);
	build(2*id+1,m+1,r);
	st[id] = st[2*id] | st[2*id+1];
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
	return vl | vr;
}

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	build(1,1,n);
	
	int count = 0;
	int j = 1;
	
	for (int i=1;i<=n;i++){
		int qval = query(1,1,n,j,i);
		while (j < i && qval > q){
			j++;
			qval = query(1,1,n,j,i);
		}
		if (i == j){
			if (a[j] <= q){
				count++;
			}
		}else{
			count += i-j+1;
		}
	}
	cout<<count;
}
