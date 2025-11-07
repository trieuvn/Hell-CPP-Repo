#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MOD = 1e9+7;

int n,m;

int dp[205][2005];

vector<int> goodRow;

bool getBit(int n, int k){
	//cout<<(bool)((1<<k)&n)<<" ";
	return (1<<k)&n;
}

int solve(int pos, int digit){
	if (pos == m)	return 1;
	if (dp[pos][digit] != 0)	return dp[pos][digit];
	int s = 0;
	for (int i : goodRow){
		bool t = true;
		for (int d=0;d<n;d++){
			if (getBit(digit,d) == getBit(i,d) && getBit(i,d) == 1){
				t = false;
				//cout<<"TTT";
				break;
			}
		}
		if (t == true){
			s = (s + solve(pos+1,i))%MOD;
		}
	}
	return dp[pos][digit] = s;
}

signed main(){
	cin>>n>>m;
	for (int j=0;j<(1<<n);j++){
		bool t = true;
		for (int d=0;d<n;d++){
			if (getBit(j,d) == getBit(j,d+1) && getBit(j,d+1) == 1){					
				t = false;
				//cout<<"TTT";
				break;
			}
		}
		if (t == true){
			goodRow.push_back(j);
			//cout<<j<<" ";
		}
	}
	//chay m
	int count = 0;
	for (int d : goodRow){
		count = (count + solve(1,d))%MOD;
	}
	cout<<count%MOD;
}
