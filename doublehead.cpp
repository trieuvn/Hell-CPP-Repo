#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1e5+5;

int n;
int a[MAX];
int stmx[4*MAX];
int stmn[4*MAX];

void build(int id, int l, int r){
	if (l == r){
		stmx[id] = a[l];
		stmn[id] = a[l];
		return ;
	}
	int m = (l+r)/2;
	build(2*id,l,m);
	build(2*id+1,m+1,r);
	stmx[id] = max(stmx[2*id], stmx[2*id+1]);
	stmn[id] = min(stmn[2*id], stmn[2*id+1]);
}

int querymax(int id, int tl, int tr, int l, int r){
	if (tl > r || tr < l){
		return LLONG_MIN;
	}
	if (tl >= l && tr <= r){
		return stmx[id];
	}
	
	int tm = (tl + tr)/2;
	
	int vl = querymax(2*id,tl,tm,l,r);
	int vr = querymax(2*id+1,tm+1,tr,l,r);
	return max(vl,vr);
}

int querymin(int id, int tl, int tr, int l, int r){
	if (tl > r || tr < l){
		return LLONG_MAX;
	}
	if (tl >= l && tr <= r){
		return stmn[id];
	}
	
	int tm = (tl + tr)/2;
	
	int vl = querymin(2*id,tl,tm,l,r);
	int vr = querymin(2*id+1,tm+1,tr,l,r);
	return min(vl,vr);
}

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	build(1,1,n);
	int sum = 0;
	
	for (int r=1;r<=n;r++){
		for (int l=1;l<=r;l++){
			int mx = querymax(1,1,n,l,r);
			int mn = querymin(1,1,n,l,r);
			
			if ((mx == a[l] || mx == a[r]) && (mn == a[l] || mn == a[r])){
				sum++;
			}
		}
	}
	
	cout<<sum;
}
