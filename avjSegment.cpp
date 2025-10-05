#include<bits/stdc++.h>
#define int long long

using namespace std;
const int sl = 5*1e+5;

typedef struct node{
	int sum;
	int pre;
	int sub;
	int ans;
}node;

int a[sl];

node t[10*sl];

node unite(node a, node b){
	node temp;
	temp.sum = a.sum +b.sum;
	temp.pre = max(a.pre, a.sum+b.pre);
	temp.sub = max(b.sub, b.sum + a.sub);
	temp.ans = max(max(a.pre, b.pre), a.sub+b.pre);
	return temp;
}

void build(int id, int l, int r){
	if (l==r){
		node temp;
		temp.sum = a[l];
		temp.pre = a[l];
		temp.sub = a[l];
		temp.ans = a[l];
		t[id] = temp;
		return ;
	}
	int m = (l+r)/2;
	build(2*id,l,m);
	build(2*id+1,m+1,r);
	t[id] = unite(t[2*id], t[2*id+1]);
}

void update(int id, int l, int r, int pos, int v){
	if (l == r){
		node temp;
		temp.sum = v;
		temp.pre = v;
		temp.sub = v;
		temp.ans = v;
		t[id] = temp;
		return ;
	}
	int m = (l+r)/2;
	if (m >= pos)
		update(2*id,l,m,pos,v);
	else	update(2*id+1,m+1,r,pos,v);
		t[id] = unite(t[id*2], t[2*id+1]);
	
	
}

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;
	cin>>n>>q;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	build(1,1,n);
	//cout<<t[1].ans<<"\n";
	for (int i=0;i<q;i++){
		int k,v;
		cin>>k>>v;
		update(1,1,n,k,v);
		if (t[1].ans > 0)
			cout<<t[1].ans<<"\n";
		else
			cout<<0<<"\n";
	}
}
