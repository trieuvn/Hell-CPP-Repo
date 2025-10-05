#include<bits/stdc++.h>

using namespace std;
const int sl = 2*1e5+5;

int a[sl];
map<int,int> tr;

int trans(int x){
	int s = 0;
	while (x > 9){
		s+=x%10;
		x/=10;
	}
	return s+x;
}

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
				//a[i] = trans(a[i]);
				if (tr[a[i]] != 0){
					//cout<<tr[a[i]]<<"\n";
					a[i] = tr[a[i]];
				}else{
					int temp = a[i];
					a[i] = trans(a[i]);
					tr[temp] = a[i];
					//cout<<a[i]<<"\n";
				}
					
			}
		}
		if (t == 2){
			int x;
			cin>>x;
			cout<<a[x]<<"\n";
		}
	}
}
