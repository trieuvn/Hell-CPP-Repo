#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1e5+5;

int n;
int a[MAX];
map<int,int> mark;

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	int count = 0;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		count += mark[a[i]^i];
		mark[a[i]^i]++;
		
		//cout<<(a[i] ^ i)<<" ";
	}
//	for (int i=2;i<=n;i++){
//		for (int j=1;j<i;j++){
//			if ((a[i]^j) == (a[j]^i)){
//				//cout<<i<<" "<<j<<"\n";
//				count++;
//			}
//		}
//	}
	cout<<count;
}
