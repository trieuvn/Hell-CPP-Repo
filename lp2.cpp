#include<bits/stdc++.h>
#define int long long

using namespace std;

int n, s=0, k, a, b;

signed main(){
	
	cin>>a>>b;
	if (b == 0){
		cout<<"-1";
		return 0;
	}
	if (a%b == 0){
		cout<<"YES";
		return 0;
	}
	
	if (a%b != 0){
		cout<<"NO";
		return 0;
	}
}
