#include<bits/stdc++.h>
#define int unsigned long long

using namespace std;
const int MOD = 1e9+7;
const int sl = 1e5+5;

int a[sl];
map<int, int> uni;
vector<int> m;

vector<int> prv;

signed main(){
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i];
		if (uni[a[i]] == 0){
			m.push_back(a[i]);
		}
		uni[a[i]]++;
	}
	int hlp4 = 0;
	
	for (int k : m){
		int t = uni[k];
		if (uni[k] >=4){
			hlp4 += ((t-3) * (t-2) * (t-1) *(t))/24;
		}
		
		int c2 = ((t-1) *(t))/2;
		
		if (c2 ==0) continue ;
		
		for (int j : prv){
			hlp4 += j*c2;	
		}
		prv.push_back(c2);
	
	}
	cout<<hlp4;
}
