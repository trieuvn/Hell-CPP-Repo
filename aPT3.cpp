#include<bits/stdc++.h>
#define int long long

using namespace std;
const int MAX = 1e5+5;

int n,m;
int a[MAX];
int b[MAX];
int c[MAX];

signed main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=m;i++){
		cin>>b[i];
	}
	int Max = 0;
	int j = 1;
	for (int i=1;i<=n;i++){
		c[a[i]]++;
		while (c[a[i]] > b[a[i]]){
			c[a[j]]--;
			j++;
		}
		Max = max(Max, i-j+1);
	}
	cout<<Max;
}
