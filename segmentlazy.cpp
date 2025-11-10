#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1e5+5;

int n,q;

int a[MAX];
int segment[4*MAX];
int lazy[4*MAX];

void push(int id, int l, int r){
	if (l == r)	return;
	if (lazy[id] != 0){
		int m = (l+r)/2;
		segment[2*id] += lazy[id] * (m - l + 1);
		segment[2*id+1] += lazy[id] * (r - m);
		
		lazy[2*id] += lazy[id];
		lazy[2*id+1] += lazy[id];
		
		lazy[id] = 0;
	}
}

void build(int id, int tl, int tr){
	if (tl == tr){
		segment[id] = a[tl];
		return ;
	}
	
	int tm = (tr+tl)/2;
	
	build(2*id,tl,tm);
	build(2*id+1,tm+1,tr);
	
	segment[id] = segment[2*id]+ segment[2*id+1];
}

int get(int id, int tl, int tr, int l, int r){
	push(id,tl,tr);
	if (l > tr || r < tl){
		return 0;
	}
	//push(id,tl,tr);
	
	if (l <= tl && tr <= r){
		return segment[id];
	}
	
	int tm = (tl + tr)/2;
	int left = get(2*id,tl,tm,l,r);
	int right = get(2*id+1,tm+1,tr,l,r);
	
	return left+ right;
}

void update(int id, int tl, int tr, int l, int r, int val){
	push(id,tl,tr);
	if (tr < l || tl > r){
		return ;
	}
	//push(id,tl,tr);
	
	if (l <= tl && r >= tr){
		segment[id] += val * (tr - tl +1);
		lazy[id] += val;
		
		return ;
	}
	int tm = (tl+tr)/2;
	update(2*id,tl,tm,l,r,val);
	update(2*id+1,tm+1,tr,l,r,val);
	segment[id] = segment[2*id] + segment[2*id+1];
}

signed main(){
	cin>>n>>q;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	
	build(1,0,n-1);
	
	for (int i=0;i<q;i++){
		int id,l,r,pos,x;
		cin>>id;
		if (id == 1){
			cin>>l>>r>>x;
			update(1,0,n-1,l-1,r-1,x);
		}
		if (id == 2){
			cin>>l>>r;
			cout<<get(1,0,n-1,l-1,r-1)<<"\n";
		}
	}
}