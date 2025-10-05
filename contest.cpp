#include <bits/stdc++.h>
#define int long long

using namespace std;
const int SL = 1e5+5;

int a[SL];
map<int,int> mark;

signed main() {
    int n;
    cin>>n;
    int x;
    cin>>x;
    int s = 0;
    for (int i=0;i<n;i++){
    	cin>>a[i];
    	s+= mark[x - a[i]];
    	mark[a[i]]++;
	}
	cout<<s;
    return 0;
}

