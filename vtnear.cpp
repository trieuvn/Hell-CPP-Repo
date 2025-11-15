#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1e5+5;

int n;
int a[MAX];

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for (int i=0;i<n;i++){
    	cin>>a[i];
	}
	
	deque<int> dq;
	
	for (int i=0;i<n;i++){
		bool best = false;
		int j = 0;
		for (int k : dq){
			if (k < a[i]){
				cout<<i-j<<" ";
				best = true;
				break;
			}
			j++;
		}
		dq.push_front(a[i]);
		if (best == false){
			cout<<0<<" ";
		}
	}
}

