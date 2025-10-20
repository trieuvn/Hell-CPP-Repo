#include<bits/stdc++.h>
#define int long long

using namespace std;

int a;

bool solve(int x){
	int i = 0;
	int s = 0;
	while (s<x){
		s += i;
		i++;
	}
	if (x == s){
		return true;
	}
	return false;
}

signed main(){
	cin>>a;
	if (solve(a) == true){
		cout<<"YES";
	}else{
		cout<<"NO";
	}
}
