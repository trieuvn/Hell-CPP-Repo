#include<bits/stdc++.h>

using namespace std;

const int MAX = 1e5+5;

int n,q;
int l,r,k;
int a[MAX];
vector<int> st[4*MAX];

void build(int id, int l, int r){
	if (l == r){
		st[id] = {a[l]};
		return ;
	}
	
	int m = (l+r)/2;
	build(2*id,l,m);
	build(2*id+1,m+1,r);
	merge(st[2*id].begin(), st[2*id].end()
		, st[2*id+1].begin(), st[2*id+1].end()
		, back_inserter(st[id]));
}

vector<int> get(int id, int tl, int tr, int l, int r){
	if (tl > r || tr < l){
		return {};
	}
	if (l <= tl && tr <= r){
		return st[id];
	}
	
	int tm = (tl + tr)/2;
	vector<int> vl = get(2*id,tl,tm,l,r);
	vector<int> vr = get(2*id+1,tm+1,tr,l,r);
	vector<int> val;
	merge(vl.begin(), vl.end()
		, vr.begin(), vr.end()
		, back_inserter(val));
	return val;
}

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	build(1,1,n);
	for (int i=0;i<q;i++){
		cin>>l>>r>>k;
		vector<int> lst = get(1,1,n,l,r);
		cout<<lst[k-1]<<"\n";
	}
}
