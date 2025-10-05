#include<bits/stdc++.h>
#define int long long

using namespace std;

int sl;
int a[200005];
int c;

int sum(int n){
	int s=0;
	for (int i=1;i<=sl;i++){
		s+= (a[i] + 2*n)*(a[i]+2*n);
		if (s > c) return s;
	}
	return s;
}

int bin(int n){
	int l = 1;
	int r = 1e9;
	int res = 0;
	while (l <= r){
		int mid = (l+r)/2;
		int k = sum(mid);
		if (k <= n){
			l = mid+1;
			res= max(res, mid);
		}else{
			r = mid-1;
		}
		//mid = (l+r)/2;
	}
	return res;
}

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int i,j,t;
	cin>>sl>>c;
	for (i=1;i<=sl;i++){
		cin>>a[i];
	}
	//cout<<sum(1);
	cout<<bin(c);
}
