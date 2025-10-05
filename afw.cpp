#include<bits/stdc++.h>
#define int long long

using namespace std;
const int sl = 1e2+5;
const int INF = 2*1e5+5;

int n;
int a[sl][sl];

int D(int x){
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({0,x});
	vector <int> d(sl,INF);
	d[x] = 0;
	while (!pq.empty()){
		x = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		cout<<x<<" ";
		for (int i=1;i<=n;i++){
			if (i == x)	continue;
			if (cost + a[x][i] < d[i]){
				d[i] = cost + a[x][i];
				pq.push({cost + a[x][i],i});
			}
		}
	}
}

signed main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	int Min = INT_MAX;
	for (int i=1;i<=n;i++){
		//Min = min(Min, D(i));
	}
	D(3);
}
