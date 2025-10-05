#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
	int n;
	cin>>n;
	int s = sqrt(n);
	int res = 0;
	for (int i=1;i<=s;i++){
		if (s%i != 0)	continue;
		if (i%2 != 0)	res++;
		if ((s/i))
	}
	cout<<res;
}
