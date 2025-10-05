#include <bits/stdc++.h>
#define int long long

using namespace std;
const int MOD = 1e9+7;
const int SL = 1e5+5;

int n,m;

int fact[SL];
int ifact[SL];

int Mul(int a, int b){
	if (b == 0)	return 0;
	if (b & 1){
		return (2*Mul(a,b/2)+a)%MOD;
	}else{
		return (2*Mul(a,b/2))%MOD;
	}
}

int Pow(int a, int b){
	if (b==0)	return 1;
	int s = Pow(a,b/2);
	if (b & 1){
		return (Mul(s,s)*a)%MOD;
	}else{
		return (Mul(s,s))%MOD;
	}
}

void process(){
	fact[0] = 1;
	for (int i=1;i<=SL-5;i++){
		fact[i] = fact[i-1] * i %MOD;
	}
	ifact[SL-5] = Pow(fact[SL-5], MOD-2);
	for (int i=SL-6;i>=0;i--){
		ifact[i] = ifact[i+1] * (i+1) %MOD;
	}
	ifact[0] = 1;
}

int C(int k, int n){
	if (k == n) return 1;
	if (k > n)	return 0;
	return ((fact[n]*ifact[k])%MOD * ifact[n-k])%MOD;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    process();
    cin >> n >> m;
    cout<<C(m,n-m+1)%MOD;
}

