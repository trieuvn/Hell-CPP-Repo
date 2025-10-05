#include<bits/stdc++.h>
#define int long long

using namespace std;

int M = 1000000007;

map<int, int> f;

int Mul(int a, int b){
	if (b == 0)	return 0;
	int x = Mul(a,b/2);
	if (b%2==0){
		return (2*x)%M;
	}else{
		return (2*x+a)%M;
	}
}

int gcd(int a, int b){
	int Max = 1;
	for (int i=1;i<=sqrt(a);i++){
		if (a%i==0){
			if (b%i==0){
				Max= i;
			}
			if (a/i != i){
				if (b%(a/i) == 0){
					return a/i;
				}
			}
		}
	}
	return Max;
}

int fib(int n){
	if (f.count(n))	return f[n];
	int k = n/2;
	
	if (n%2==0){
		int x1 = fib(k);
		int x2 = fib(k-1);
		f[n] = ((Mul(x1,x1)) +(Mul(x2,x2)))%M;
		return f[n];
	}else{
		int x1 = fib(k);
		int x2 = fib(k-1);
		int x3 = fib(k+1);
		f[n] = (Mul(x1,x3) + Mul(x1,x2))%M;
		return f[n];
	}
}

signed main(){
	int a,b;
	f[0]=1;
	f[1] =1;
	cin>>a>>b>>M;
	int k = gcd(a,b);
	cout<<fib(k-1)%M;
}
