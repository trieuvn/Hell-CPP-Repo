#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	long long n,day,j,i;
	long long sum = 0;
	cin>>n;
	long long t[n+1];
	long long p[n+1];
	vector<long long> dp(n+1,LONG_MAX);
	priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
	//vector<long> dp(n+1,LONG_MAX);
	for (i=1;i<=n;i++){
		cin>>t[i];
		cin>>p[i];
		//pq.push({t[i],p[i]});
	}
	//cout<<"DSDSDSDS\n";
	//dp[1] = p[1];
	for (day = 1;day<=t[1];day++){
		dp[day] = p[1];
	}
	j=1;
	for (day=2;day<=n;day++){
		pq.push({p[day],day});
		while (!pq.empty() && t[pq.top().second] < day)	pq.pop();
		//while (!pq.empty()){
		if (!pq.empty()){
			for (j=pq.top().second-1;j<=t[pq.top().second];j++){
				dp[day] = min(dp[day],dp[j]+pq.top().first);
			}
			//pq.pop();
		}
			
		//}
	}
	cout<<dp[n];
	for (i=0;i<=n;i++){
		cout<<dp[i]<<" ";
	}
}

