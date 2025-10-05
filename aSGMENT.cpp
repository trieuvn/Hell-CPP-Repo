#include<bits/stdc++.h>
#define int long long

using namespace std;
const int sl = 1e+5;

int a[sl];

int t[10*sl];

int lazy[10*sl];


signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	build(1,1,n);
	cin>>q;
	for (int i=0;i<q;i++){
		int t;
		cin>>t;
		if (t == 1){
			int x,y,val;
			cin>>x>>y>>val;
			update(1,1,n,x,y,val);
		}
		if (t == 2){
			int l,r;
			cin>>l>>r;
			cout<<get(1,1,n,l,r)<<"\n";
		}
	}
	
}
