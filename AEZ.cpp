#include<bits/stdc++.h>
#define int long long

using namespace std;

map<int, int> m;

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int q;
	cin>>q;
	for (int i=0;i<q;i++){
		int l,r,v;
		cin>>l>>r>>v;
		m[l] += v;
		m[r+1] -= v;
	}	
	int Max = 0;      
    int count = 0;        
    int cur = 0;  
    auto p = m.begin();
	for (auto it = m.begin(); it != m.end(); ++it) {
        cur += it->second; 
        if (cur > Max) {
            Max = cur;  
            p = it;
            count = 1;           
        } else if (cur == Max) {
            count++;        
        }
    }
	auto p2 = p++;
	cout<<Max<<" "<<p->first - p2->first ;
}
