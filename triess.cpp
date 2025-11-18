#include<bits/stdc++.h>
#define int int64_t

using namespace std;

const int MAX = 1e6+5;

int n;
int sum = 0;
string s;
int cnt;

int a[MAX];
int tr[MAX][26];
int stop[MAX];
int sl[MAX];
int h[MAX];

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
	}
	stop[u]++;
}

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>s;
		add();
	}
	int ans = 0;
	
	for (int i=0;i<=cnt;i++){
		int sum = 0;
		int sum_sq = 0;
		for (int j=0;j<26;j++){
			int v = tr[i][j];
			sum += sl[v];
			sum_sq+= sl[v] * sl[v];
		}
		
		int pair = (sum*sum - sum_sq)/2;
		
		if (pair > 0){
			ans += pair * (h[i]+ 1);
		}
	}
	
	cout<<ans;
}
