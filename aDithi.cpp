#include<bits/stdc++.h>
#define int long long

const int sl = 1e3+5;

const int MAX = 1e6;

using namespace std;

set<int> a;

void dg(int toa){
	int x = 2;
	while (true){
		int sum = 1+x;
		if (sum >= MAX)	return ;
		for (int i=2;i<=toa;i++){
			sum+=pow(x,i);
		}
		x++;
		a.insert(sum);
	}
}

bool isDG(int x){
	
}

signed main(){
	for (int i=2;i<=5;i++){
		dg(i);
	}
	for (auto it=a.begin();it!=a.end();it++){
		cout<<*it<<" ";
	}
}
