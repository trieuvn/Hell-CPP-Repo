#include<bits/stdc++.h>
#define int long long

using namespace std;

const int sl = 2*1e5+5;

int n,q;
int a[sl];
int t[10][10*sl];

bool chk(int i, int k){
	if (i%k==0)	return true;
	while (i>0){
		if (i%10==k) 	return true;
		i/=10;
	}
	return false;
}

void build(int id, int l, int r){
	if (l == r){
		for (int i=1;i<=9;i++){
			t[i][id] = a[l];
			if (chk(l,i)){
				t[i][id] = 2*t[i][id];
			}
		}
		
		return;
	}
	int m = (l+r)/2;
	build(2*id,l,m);
	build(2*id+1,m+1,r);
	for (int i=1;i<=9;i++){
		t[i][id] = t[i][2*id] + t[i][2*id+1];
	}
}

void update(int id, int l, int r, int k, int value){
	if (l > r)	return;
	if (l == r && l == k){
		for (int i=1;i<=9;i++){
			t[i][id] = value;
			if (chk(k,i)){
				t[i][id]*=2;
			}
		}
		return;
	}
	int m = (l+r)/2;
	if (m >= k){
		update(2*id,l,m,k,value);
	}else{
		update(2*id+1,m+1,r,k,value);
	}
	for (int i=1;i<=9;i++){
		t[i][id] = t[i][2*id] + t[i][2*id+1];
	}
}

int query(int id, int l, int r, int ql, int qr, int k){
	if (ql > r || qr < l)	return 0;
	if (ql <= l && qr >= r){
		return t[k][id];
	}
	int m = (l+r)/2;
	return query(2*id,l,m,ql,qr,k) + query(2*id+1,m+1,r,ql,qr,k);
}


signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	build(1,1,n);
	//for (int i=1;i<=20;i++){
	//	cout<<t[2][i]<<" ";
	//}
	for (int i=0;i<q;i++){
		int t;
		cin>>t;
		if (t == 1){
			int x,v;
			cin>>x>>v;
			update(1,1,n,x,v);
			a[x] = v;
		}
		if (t == 2){
			int l,r,k;
			cin>>l>>r>>k;
			int res = query(1,1,n,l,r,k);

			cout<<res<<"\n";
		}
	}
	
}
