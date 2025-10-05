#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	set<int> s(a.begin(), a.end());
	vector<int> b(s.begin(), s.end());
	int result = 0;
	for (int x: a) {
    	int k = lower_bound(b.begin(), b.end(), x) - b.begin();
    	b[k] = x;
    	result = max(result, k);
	}
	cout<<result
}
