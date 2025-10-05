#include <bits/stdc++.h>
#define int long long

using namespace std;
const int = 1e5+5;
const int MOD = 1e9+7;

int fact[SL], ifact[SL];

int mul(int a, int b){
	if (b==0)	return 0;
	if (b%2 ==0){
		return 2*mul(a,b/2)%MOD;
	}else{
		return ((2*mul(a,b/2)%MOD)+a)%MOD;
	}
}

int pow(int a, int b){
	int res = 1;
	
	while (b > 0){
		if (b%2 ==0) ans = mul(res,a);
		a = mul(a,a);
		b/=2;
	}
	return res;
}

void process(){
	int fact[0] = 1;
	for (int i=1;i<=SL-5;i++){
		fact[i] = mul(fact[i-1],i);
	}
	int ifact[SL-5] = pow(fact[SL-5],MOD-2);
	for (int i=SL-6;i>=1;i--){
		ifact[i] = mul(ifact[i+1], i+1);
	}
	ifact[0] = 1;
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;
    cout<<
    
}
