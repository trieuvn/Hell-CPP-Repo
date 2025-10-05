#include<bits/stdc++.h>
#define int long long

using namespace std;
const int sl = 2*1e5+5;

int a[sl];

int trans(int x){
	int s = 0;
	while (x > 9){
		s+=x%10;
		x/=10;
	}
	return s+x;
}
vector<bool> chk(sl,false);

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	int q;
	cin>>q;
	for (int i=0;i<q;i++){
		int t;
		cin>>t;
		if (t == 1){
			int l,r;
			cin>>l>>r;
			for (int i=l;i<=r;i++){
				if (chk[i] == true) continue;
				a[i] = trans(a[i]);
				if (a[i] < 10) chk[i] = true;
			}
		}
		if (t == 2){
			int x;
			cin>>x;
			cout<<a[x]<<"\n";
		}
	}
	cout<<trans(69);
}
