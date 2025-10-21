#include<bits/stdc++.h>
#define int long long

using namespace std;
const int MAX = 1e5+5;

int t,n,m;

int a[MAX];

int test(){
	for (int i=m;i>=1;i--){
		int s = 0;
		for (int j=0;j<n;j++){
			s += (a[j] ^ i);
		}
		if (s <= m){
			cout<<1<<" ";
		}else{
			cout<<0<<" ";
		}
	}
	return -1;
}

bool solve(int x){
	int s = 0;
	for (int j=0;j<n;j++){
		s += (a[j] ^ x);
	}
	if (s <= m){
		return true;
	}
	
	return false;
}

int search(){
	if (solve(0) == false)	return -1;
	int left = 0;
	int right = MAX;
	int mid = (left+right)/2;
	int res = -1;
	while (left<=right){
		if (solve(mid) == true){
			left = mid + 1;
			if (mid > res) res = mid;
		}
		if (solve(mid) == false){
			right = mid - 1;
			
		}
		mid = (left+right)/2;
	}
	return res;
}



signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while (t--){
		cin>>n>>m;
		for (int i=0;i<n;i++){
			cin>>a[i];
		}
		cout<<search()<<"\n";
	}
}
