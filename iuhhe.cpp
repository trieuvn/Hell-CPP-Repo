#include <bits/stdc++.h>
#define int unsigned long long
 
using namespace std;
 
const int MOD = 1e9+7;
const int sl = 1e6+5;
 
int q;
 
int fact[sl];
int ifact[sl];
 
int Mul(int a, int b){
	if (b==0)	return 0;
	if (b%2==0){
		return (2*Mul(a,b/2))%MOD;
	}else{
		return ((2*Mul(a,(b-1)/2))%MOD + a)%MOD;
	}
}
 
int Pow(int a, int b){
	if (b ==0) return 1;
	int x = Pow(Mul(a,a),b/2);
	if (b%2==0){
		return x;
	}else{
		return Mul(x,a);
	}
}
 
void process(){
	fact[0] = 1;
	for (int i=1;i<=sl-5;i++){
		fact[i] = fact[i-1] * i %MOD;
	}
	ifact[sl-5] = Pow(fact[sl-5], MOD-2);
	for (int i=sl-6;i>=1;i--){
		ifact[i] = ifact[i+1] * (i+1) %MOD;
	}
	ifact[0] = 1;
}
 
int C(int n, int k){
	if (k==0 || n==k) return 1;
	if (k>n)	return 0;
	return Mul(Mul(fact[n],ifact[k]), ifact[n-k])%MOD;
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin>>n;
    process();
    cout<<n*(n-1)*(n-2)*(n-3)/24;
}
