#include<bits/stdc++.h>

using namespace std;

const int SL = 1e5+5;

int a[SL];

multiset<int> m;

signed main(){
	int n,k;
	cin>>n>>k;
	int j=0;
	int s = 0;
	for (int i=0;i<n;i++){
		cin>>a[i];
		m.insert(a[i]);
		auto Max = m.end();
		Max--;
		auto Min = m.begin();
		while (*Max - *Min > k){
			m.erase(m.find(a[j]));
			j++;
			Max = m.end();
			Max--;
			Min = m.begin();
		}
		s+=i-j+1;
	}
	cout<<s;
}
