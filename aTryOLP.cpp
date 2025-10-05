#include<bits/stdc++.h>

using namespace std;

const int sl = 2*1e5+5;

int n,k;
set<int> a;
bool res[sl];

signed main(){
	cin>>n>>k;
	int t;
	cin>>t;
	a.insert(t);
	res[1] = true;
	for (int i=2;i<=n;i++){
		cin>>t;
		//auto r = a.upper_bound(k+t);
		auto l = a.lower_bound(t-k);
		if (l != a.end() && *l <= k+t){
			res[i] = true;
			a.insert(t);
		}
		
	}
	for (int i=1;i<=n;i++){
		cout<<res[i]<<" ";
	}
}
