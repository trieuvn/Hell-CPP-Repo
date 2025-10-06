#include<bits/stdc++.h>
#define int long long

using namespace std;
const int MAX = 1e5+5;

int n;

int a[MAX];
int b[MAX];
int c[MAX];

int calc(int ai, int bi, int ci){
	return abs(a[ai]-b[bi]) + abs(b[bi]-c[ci]) + abs(c[ci]-a[ai]);
}

signed main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n;i++){
		cin>>b[i];
	}
	for (int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(a,a+n+1);
	sort(b,b+n+1);
	sort(c,c+n+1);
	int Min = LLONG_MAX;
	int ai = 1;
	int bi = 1;
	int ci = 1;
	while (ai != n+1 && bi != n+1 && ci != n+1){
		Min = min(Min, calc(ai,bi,ci));
		if (a[ai] <= b[bi] && a[ai] <= c[ci])	ai++;
		else if (b[bi] <= c[ci])	bi++;
		else ci++;
	}
	cout<<Min;
}
