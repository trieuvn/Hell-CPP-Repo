#include<bits/stdc++.h>
#define int long long

using namespace std;

int n,k,sum=0;
string s;
map<string, int> dp;

void BT(int cur){
	if (cur == n){
		return ;
	}
	if (s[cur] == 'W'){
		dp["COW"]+=dp["CO"]; 
	}
	if (s[cur] == 'O'){
		dp["CO"]+=dp["C"]; 
	}
	if (s[cur] == 'C'){
		dp["C"]++; 
	}
	BT(cur+1);
}

signed main(){
	cin>>n;
	cin>>s;
	BT(0);
	cout<<dp["COW"];
}
