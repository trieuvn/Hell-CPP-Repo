#include<bits/stdc++.h>
#define int long long

using namespace std;

int sl;
int a[200001];

int sum(int n){
	int s=0;
	for (int i=0;i<sl;i++){
		s+=(a[i]+(n*2))*(a[i]+(n*2)) - a[i]*a[i];
	}
	return s;
}

int bin(int n){
	int l = 0;
	int r = n;
	int mid = (l+r)/2;
	while (l <= r){
		int k = sum(mid);
		//cout<<k<<" ";
		if (n == k){
			return mid;
		}else if (n > k){
			l = mid+1;
		}else{
			r = mid-1;
		}
		mid = (l+r)/2;
	}
	if (n >= sum(mid+1))	return mid+1;
	else if (n >= sum(mid))	return mid;
	else return mid-1;
}

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c,i,j,t;
	cin>>sl>>c;
	for (i=0;i<sl;i++){
		cin>>a[i];
	}
	cout<<bin(c);
}
