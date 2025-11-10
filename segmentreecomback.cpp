#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1e5+5;

int n,q;

int a[MAX];
int segment[4*MAX];

void build(int id, int tl, int tr){
	if (tl == tr){
		segment[id] = a[tl];
		return ;
	}
	
	int tm = (tr+tl)/2;
	
	build(2*id,tl,tm);
	build(2*id+1,tm+1,tr);
	
	segment[id] = segment[2*id] + segment[2*id+1];
}

int get(int id, int tl, int tr, int l, int r){
	if (l > tr || r < tl){
		return 0;
	}
	if (l <= tl && tr <= r){
		return segment[id];
	}
	
	int tm = (tl + tr)/2;
	int left = get(2*id,tl,tm,l,r);
	int right = get(2*id+1,tm+1,tr,l,r);
	
	return left + right;
}

void update(int id, int tl, int tr, int pos, int val){
	if (pos < tl || tr < pos){
		return ;
	}
	if (tl == tr){
		segment[id] = val;
		return ;
	}
	int tm = (tl+tr)/2;
	update(2*id,tl,tm,pos,val);
	update(2*id+1,tm+1,tr,pos,val);
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
			cin>>pos>>x;
			update(1,0,n-1,pos-1,x);
		}
		if (id == 2){
			cin>>l>>r;
			cout<<get(1,0,n-1,l-1,r-1)<<"\n";
		}
	}
}