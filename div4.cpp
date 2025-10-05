#include<bits/stdc++.h>
#define int long long

using namespace std;
/*
3
2 4
2 1
4 0
*/

const int MAX = 2*1e5+5;

int t, n, m, x, y, a, b[MAX];

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while (t--){
		cin>>n;
		int le[MAX];
		int slle = 0;
		int point = 0;
		int pointchan = 0;
		for (int i=0;i<n;i++){
			cin>>a;
			if (a%2 == 0){
				pointchan+=a;
			}else{
				le[slle] = a;
				slle++;
			}
		}
		sort(le,le+slle);
		int imin = 0;
		int imax = slle-1;
		for (int i=imax;i>=slle/2;i--){
			point+=le[i];
		}
		if (point >0){
			point+=pointchan;
		}
		cout<<point<<"\n";
	}
	
}
