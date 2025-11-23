#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1e6+5;

int n,q;
int a[MAX];
int bit[MAX];

void update(int idx, int val){
	for (;idx<=n;idx += idx & -idx){
		bit[idx] += val;
	}
}

int get(int idx){
	int sum = 0;
	for (;idx>0;idx -= idx & -idx){
		sum += bit[idx];
	}
	return sum;
}

signed main(){
	cin>>n>>q;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		update(i,a[i]);
	}
	
	for (int i=0;i<q;i++){
		int id;
		cin>>id;
		if (id == 1){
			int i,x;
			cin>>i>>x;
			int diff = x - a[i];
			update(i,diff);
			a[i] = x;
		}
		if (id == 2){
			int l,r;
			cin>>l>>r;
			cout<<get(r) - get(l-1)<<"\n";
		}
	}
}
