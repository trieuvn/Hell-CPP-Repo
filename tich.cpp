#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1e5+5;

int n;
int a[MAX];
int stmax[4*MAX];
int stmin[4*MAX];

void build(int id, int l, int r){
	if (l == r){
		stmax[id] = a[l];
		stmin[id] = a[l];
		return ;
	}
	int m = (l+r)/2;
	build(2*id,l,m);
	build(2*id+1,m+1,r);
	
	stmax[id] = max(stmax[2*id], stmax[2*id+1]);
	stmin[id] = min(stmin[2*id], stmin[2*id+1]);
}

pair<int,int> query(int id, int tl, int tr, int l, int r){
	if (tl > r || tr < l){
		return {LLONG_MIN, LLONG_MAX};
	}
	
	if (tl >= l && tr <= r){
		return {stmax[id], stmin[id]};
	}
	
	int tm = (tl+tr)/2;
	pair<int,int> vl = query(2*id,tl,tm,l,r);
	pair<int,int> vr = query(2*id+1,tm+1,tr,l,r);
	return {max(vl.first,vr.first), min(vl.second,vr.second)};
}

signed main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	build(1,1,n);
	
	int sum = 0;
	for (int l=1;l<=n;l++){
		for (int r=l;r<=n;r++){
			pair<int,int> values = query(1,1,n,l,r);
			int mx = values.first;
			int mn = values.second;
			
			sum += mx*mn;
		}
	}
	cout<<sum;
}
