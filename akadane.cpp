#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1e5+5;

int n;
int a[MAX];
int dpmx[MAX];
int dpmn[MAX];
int sum;

signed main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	
	for (int i=1;i<=n;i++){
		dpmx[i] = max(a[i], a[i] + dpmx[i-1]);
	}
	int res = LLONG_MIN;
	for (int i=1;i<=n;i++){
		dpmn[i] = min(a[i], a[i] + dpmn[i-1]);
	}
	
	for (int i=1;i<=n;i++){
		res = max(res, dpmx[i]);
		res = max(res, sum - dpmn[i]);
	}
	
	cout<<res;
}
