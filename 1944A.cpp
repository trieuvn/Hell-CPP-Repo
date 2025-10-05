#include<bits/stdc++.h>

using namespace std;

int t, n, k;

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while (t--){
		cin>>n>>k;
		int cost = k;
		int lost = 0;
		if (k >= n-1){
			cout<<1<<"\n";
			continue;
		}
		for (int i=n;i>1;i--){
			cost = k - i-1 + lost;
			if (cost <= 0){
				cout<<n-lost<<"\n";
				break;
			}
			
			lost++;
			
		}
	}
}
