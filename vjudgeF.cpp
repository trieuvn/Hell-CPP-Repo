#include<bits/stdc++.h>
#define int long long

using namespace std;

const int sl = 1e5+5;

int a[sl];

vector<int> mh(sl,0);

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int left[sl];
	int right[sl];
	int value[sl];
	vector<int> t(sl,0);

	int n,m,k;
	cin>>n>>m>>k;
	int i,j;
	for (i=1;i<=n;i++)	cin>>a[i];
	
	for (i=1;i<=m;i++){
		cin>>left[i]>>right[i]>>value[i];
	}
	
	int l,r;
	for (i=0;i<k;i++){
		cin>>l>>r;
		t[l] += 1;
		t[r+1] -= 1;
	}
	for (i=1;i<=m;i++){
		t[i] += t[i-1];
	}
	
	for (i=1;i<=m;i++){
		mh[left[i]] += value[i]*t[i];
		mh[right[i]+1] -= value[i]*t[i];
	}
	
	for (i=1;i<=n;i++){
		mh[i] += mh[i-1];
	}
	for (i=1;i<=n;i++){
		cout<<a[i]+mh[i]<<" ";
	}
}
