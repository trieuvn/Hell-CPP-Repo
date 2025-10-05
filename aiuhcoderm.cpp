#include<bits/stdc++.h>
#define int long long

using namespace std;

const int sl = 1e5+5;
map<int, int> m;

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,x;
	cin>>n>>x;
	int prefix[sl];
	prefix[0] =0;
	m[0]++;
	int s=0;
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		prefix[i] = prefix[i-1] + t;
		s+= m[prefix[i]%x];
		m[prefix[i]%x]++;
	}
	cout<<s;
}
