#include<bits/stdc++.h>
#define int unsigned long long

using namespace std;

int UC(int a, int b){
	priority_queue<int,vector<int>> pq;
	int i;
	for (i=1;i<=sqrt(a);i++){
		if (a%i == 0){
			if (a/i != i){
				if (b%(a/i) == 0){
					return a/i;
				}
			}
			pq.push(i);
		}
	}
	while (b%pq.top()!=0)	pq.pop();
	return pq.top();
}

signed main(){
	int a,b,m,i;
	cin>>a>>b>>m;
	int fib[a+b];
	fib[0] = 0;
	fib[1] = 1;
	for (i=2;i<=a || i<=b;i++){
		fib[i] = (fib[i-1] + fib[i-2])%m;
	}
	cout<<UC(fib[a],fib[b])%m;
}
