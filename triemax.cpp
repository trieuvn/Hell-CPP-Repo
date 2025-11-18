#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1e6+5;

int n;
int sum = 0;
string s;
int cnt;

int h[MAX];
int tr[MAX][26];
int sl[MAX];
int Max;
int res;

void add(){
	int u = 0;
	for (char c : s){
		int v = c - 'a';
		if (tr[u][v] == 0){
			tr[u][v] = ++cnt;
			h[tr[u][v]] = h[u] + 1;
		}
		u = tr[u][v];
		sl[u]++;
		Max = max(Max, sl[u]*h[u]);
	}
}

void dfs(int u, int c){
	if (sl[u] == 1){
		res += h[u];
		return ;
	}
	for (int i=0;i<26;i++){
		if (tr[u][i] > 0){
			dfs(tr[u][i],i);
		}
	}
}

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>s;
		add();
	}
	dfs(0,-1);
	cout<<res;
}
