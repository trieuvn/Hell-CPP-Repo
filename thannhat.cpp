#include<bits/stdc++.h>
#define int int64_t

using namespace std;

const int MAX = 2e5+5;
const int INF = 1e18;
const int MOD = 1e9+7;

int n;
int a[MAX];

int gcd(int a, int b){
	return (b == 0) ? a : __gcd(a,b);
}

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	int best = 0;
	for (int i=1;i<n;i++){
		for (int j=0;j<i;j++){
			best = max(best, gcd(a[i],a[j]));
		}
	}
	
	cout<<best;
}
