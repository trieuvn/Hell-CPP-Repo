#include<bits/stdc++.h>
#define int long long
 
using namespace std;
const int sl = 2*1e6+5;

vector<int> path[sl];

int sp;

int n,m,s,f;


set<int> imp;

int shortest_path(int x, int des){
	vector<int> trace(sl,-1);
	vector<bool> vis(sl,false);
	queue<pair<pair<int,int>, int>> q;
	q.push({{x,-1},0});
	vis[x] = true;
	
	while (!q.empty()){
		x = q.front().first.first;
		int par = q.front().first.second;
		int dist = q.front().second;
		q.pop();
		trace[x] = par;
		
		if (x == des){
			for (int i = x; i != -1; i = trace[i]){
				imp.insert(i);				
			}
			return dist;
		}
		
		for (int k : path[x]){
			if (vis[k] == true)	continue;
			//trace[k] = par;
			
			vis[k] = true;
			q.push({{k,x},dist+1});
			
		}
	}
	return -1;
}

vector<int> trace(sl,-1);
void dfs(int x, int par, int cost){	
	if (cost > sp)	return ;
	trace[x] = par;
	
	if (x == f){
		set<int> temp;
		for (int i = x;i != -1;i = trace[i]){
			if (imp.count(i)>0){
				temp.insert(i);
			}
			
		}
		imp = temp;
		return;
	}
	for (int k : path[x]){
		if (k == par) continue ;
		dfs(k,x,cost+1);
	}
}
 
signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>s>>f;
	for (int i=0;i<m;i++){
		int u,v,z;
		cin>>u>>v>>z;
		path[u].push_back(v);
		path[v].push_back(u);
	}
	sp = shortest_path(s,f);
	dfs(s,-1,0);
	for (auto it = imp.begin();it != imp.end();it++){
		cout<<*it<<" ";
	}
	/*for (int i=0;i<=10;i++){
		cout<<imp[i];
	}*/
}
