#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1e5+5;
const int BLOCKSIZE = 2;

int n,q;
int block[MAX];
int a[MAX];

void build(){
	for (int i=1;i<=n;i++){
		int id = i/BLOCKSIZE+1;
		block[id] += a[i];
	}
}

void update(int i, int x){
	a[i] = x;
	int bid = i/BLOCKSIZE+1;
	int l = bid*BLOCKSIZE - BLOCKSIZE;
	int r = bid*BLOCKSIZE-1;
	block[bid] = 0;
	for (int i=l;i<=r;i++){
		block[bid] += a[i];
	}
	//cout<<"ID "<<bid<<" ";
}

int get(int left, int right){
	int bleft = left/BLOCKSIZE+1;
	int bright = right/BLOCKSIZE+1;
	int sum = 0;
	if (bleft == bright){
		for (int i=left;i<=right;i++){
			sum+=a[i];
		}
		return sum;
	}
	
	int limit = bleft*BLOCKSIZE-1;
	for (int i=left;i<=limit;i++){
		sum += a[i];
	}
	limit = bright*BLOCKSIZE - BLOCKSIZE;
	for (int i=limit;i<=right;i++){
		sum += a[i];
	}
	for (int b=bleft+1;b<bright;b++){
		sum+=block[b];
	}
	return sum;
}

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	build();
	
	for (int i=0;i<q;i++){
		int id;
		cin>>id;
		if (id == 1){
			int idx, x;
			cin>>idx>>x;
			update(idx, x);
		}
		if (id == 2){
			int l,r;
			cin>>l>>r;
			cout<<get(l,r)<<"\n";
		}
	}
}
