#include<bits/stdc++.h>
#define int long long

using namespace std;

const int INF = LONG_MAX;

int n,L;
vector<int> graph[505];
int S[505];
int A[505][505];
//int dp[505][505];
bool vis[505];
vector<vector<int>> dp(505, vector<int>(505, -INF));

void solve(int cur){
	vis[cur] = true;
	for (int i=0;i<=S[cur];i++){
		dp[cur][i] = A[cur][i]; 
	}
	for (int u : graph[cur]){
		if (!vis[u]){
			solve(u);
			for (int i=S[cur];i>=0;i--){
				for (int j=0;j<=i;j++){
					dp[cur][i] = max(dp[cur][i], dp[cur][i-j] + dp[u][j]);
				}
			}
		}
	}
	
}

void Input(){
	cin>>n>>L;
	int p;
	for (int i=2;i<=n;i++){
		cin>>p;
		graph[p].push_back(i);
	}
	for (int i=1;i<=n;i++){
		cin>>S[i];
	}
	for (int i=1;i<=n;i++){
		for (int j=0;j<=L;j++){
			cin>>A[i][j];
		}
	}
}

signed main(){
	Input();
	solve(1);
	int Max = 0;
	for (int i=0;i<=L;i++){
		Max = max(Max, dp[1][i]);
	}
	cout<<Max;
}
