//cach khac cua Trieu nha :D
#include<bits/stdc++.h>

using namespace std;

typedef struct cap{
	long h;
	long p;
}cap;

int main(){
	long n,i;
	cin>>n;
	if (n == 1){
		cout<<"2";
		return 0;
	}
	if (n == 0){
		cout<<"0";
		return 0;
	}
	vector<cap> x;
	for (i=1;i<=sqrt(n);i++){
		if (n%i == 0){
			if (n/i != 1)
				x.push_back({i,n/i});
			if (n/i != i){
				if (i != 1)
					x.push_back({n/i,i});
			}
		}
	}
	long Min = LONG_MAX;
	for (cap k : x){
		Min = min(Min, (k.h+1)*k.p);
	}
	cout<<Min;
}
