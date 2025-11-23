#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1e5+5;

int n,k;
vector<pair<int,int>> adj[MAX];
int cafeList[MAX];
bool isCafe[MAX];
vector<int> shortest1st(MAX, LLONG_MAX);
vector<int> shortest2nd(MAX, LLONG_MAX);
vector<int> res(MAX, LLONG_MAX);

void DS(){
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	for (int i=0;i<k;i++){
		pq.push({0,cafeList[i]});
	}
	
	
	while (!pq.empty()){
		int cost = pq.top().first;
		int u = pq.top().second;
		pq.pop();
		for (pair<int,int> child : adj[u]){
			int v = child.first;
			int w = child.second;
			int newcost = w + cost;
			if (newcost < shortest1st[v]){
				shortest2nd[v] = shortest1st[v];
				shortest1st[v] = newcost;
				pq.push({newcost,v});
			}
			else if(newcost < shortest2nd[v]){
				shortest2nd[v] = newcost;
				pq.push({newcost,v});
			}
		}
	}
}

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	int u,v,w;
	for (int i=0;i<n-1;i++){
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	
	for (int i=0;i<k;i++){
		cin>>cafeList[i];
		isCafe[cafeList[i]] = true;
	}
	DS();
	for (int i=1;i<=n;i++){
		if (isCafe[i]){
			cout<<shortest2nd[i]<<"a ";
		}else{
			cout<<shortest1st[i]<<"b ";
		}
	}
}
