#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 5005;

int n;
int f[MAX];
int sum;
bool visited[MAX];

bool dfs(int par, int cur){
	if (visited[cur] == true && sum == 4){
		return true;
	}else if (visited[cur] == true){
		return false;
	}
	visited[cur] = true;
	if (f[cur] == par){
		return false;
	}
	sum++;
	return dfs(cur, f[cur]);
}

signed main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>f[i];
	}
	for (int i=1;i<=n;i++){
		for (int i=1;i<=n;i++){
			visited[i] = false;
		}
		sum = 1;
		if (dfs(-1,i) == true){
			cout<<"YES";
			return 0;
		}
		//cout<<i<<" "<<sum<<"\n";
	}
	cout<<"NO";
}
