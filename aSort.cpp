#include<bits/stdc++.h>
#define int long long

using namespace std;
const int sl = 5*1e6+5;

typedef struct node{
	int idx;
	int val;
}node;
int n;
node a[sl];

bool comp(node x, node y){
	if (x.val == y.val){
		return x.idx < y.idx;
	}
	return x.val < y.val;
}

int binValL(int val){
	int left = 0;
	int right = n-1;
	int m = (left+right)/2;
	int res = -1;
	while (left <= right){
		if (a[m].val == val){
			res = m;
			right = m -1;
		}else if (a[m].val < val){
			left = m + 1;
		}else{
			right = m-1;
		}
		m = (left+right)/2;
	}
	return res;
}

int binValR(int val){
	int left = 0;
	int right = n-1;
	int m = (left+right)/2;
	int res = -1;
	while (left <= right){
		if (a[m].val == val){
			res = m;
			left = m +1;
		}else if (a[m].val < val){
			left = m + 1;
		}else{
			right = m-1;
		}
		m = (left+right)/2;
	}
	return res;
}

int binIdxL(int l, int r, int ql){
	int m = (l+r)/2;
	int res = -1;
	while (l <= r){
		if (a[m].idx >= ql){
			res = m;
			r = m-1;
		}else{
			l = m+1;
		}
		m = (l+r)/2;
	}
	return res;
}

int binIdxR(int l, int r, int qr){
	int m = (l+r)/2;
	int res = -1;
	while (l <= r){
		if (a[m].idx <= qr){
			res = m;
			l = m+1;
		}else{
			r = m-1;
		}
		m = (l+r)/2;
	}
	return res;
}

signed main(){
	int q;
	cin>>n>>q;
	for (int i=0;i<n;i++){
		int v;
		cin>>v;
		a[i].idx = i;
		a[i].val = v;
	}
	
	sort(a,a+n,comp);
	
	for (int i=0;i<q;i++){
		int l,r,x;
		cin>>l>>r>>x;
		l--;
		r--;
		int left = binValL(x);
		int right = binValR(x);
		int idxL = binIdxL(left,right,l);
		int idxR = binIdxR(left,right,r);
		if (idxL == -1 || idxR == -1){
			cout<<"0\n";
			continue;
		}
		cout<<idxR-idxL+1<<"\n";
	}
}
