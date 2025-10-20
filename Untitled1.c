#include<bits/stdc++.h>
#define int long long

using namespace std;

int a;

int solve(int x){
	ins s = 0;
	for (int i = 1;i<=sqrt(x);i++){
		if (x%i == 0){
			s++;
		}
	}
	cout<<s;
}

signed main(){
	cin>>a;
	cout<<solve(a);
}
