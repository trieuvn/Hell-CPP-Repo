#include<bits/stdc++.h>
#define int unsigned long long

using namespace std;

int m;
map<int, int> F;

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

int f(int n) {
	if (F.count(n)) return F[n];
	int k=n/2;
	if (n%2==0) { // n=2*k
		return F[n] = (f(k)*f(k) + f(k-1)*f(k-1))%m ;
	} else { // n=2*k+1
		return F[n] = (f(k)*f(k+1) + f(k-1)*f(k))%m ;
	}
}

signed main(){
  ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int a,b,i;
	cin>>a>>b>>m;
	F[0] = 1;
	F[1] = 1;
	int u = UC(a,b);
	
	cout << (u==0 ? 0 : f(u-1));
}

