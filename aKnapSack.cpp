#include<bits/stdc++.h>
#define int long

using namespace std;
const int SL = 1e5+5;

int n;

int a[SL];

vector<int> res;
vector<int> trace;
int dp[SL];

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	int pos = 0;
	int ans = a[0];
	dp[0] = 1;
	res.push_back(a[0]);
	for (int i=1;i<n;i++){
		if (a[i] > res.back()){
			res.push_back(a[i]);
			pos = i;
			ans = res.size();
			dp[i] = ans;
		}else{
			int k = lower_bound(res.begin(),res.end(),a[i])-res.begin();
			res[k] = a[i];
			dp[i] = k+1;
		}
	}
	cout<<res.size()<<"\n";
	trace.push_back(pos+1);
	//cout<<"ans"<<ans;
	ans--;
	for (int i=pos-1;i>=0;i--){
		if (a[i] < a[pos] && dp[i] == ans){
			trace.push_back(i+1);
			ans--;
			pos=i;
		}
	}
	reverse(trace.begin(),trace.end());
	for (int x : trace)	cout<<x<<" ";
	
}
