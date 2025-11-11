#include<bits/stdc++.h>

using namespace std;

int n;

signed main(){
	cin>>n;
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	int l,r;
	for (int i=0;i<n;i++){
		cin>>l>>r;
		pq.push({l,r});
	}
	int res = 0;
	int bestl = pq.top().first;
	int bestr = pq.top().second;
	pq.pop();
	while (!pq.empty()){
		l = pq.top().first;
		r = pq.top().second;
		pq.pop();
		
		if (bestl <= l && l <= bestr){
			bestl = min(bestl, l);
			bestr = max(bestr, r);
		}else{
			res = max(res, bestr - bestl);
			bestl = l;
			bestr = r;
		}
	}
	res = max(res, bestr - bestl);
	cout<<res;
}
