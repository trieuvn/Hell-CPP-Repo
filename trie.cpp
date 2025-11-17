#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 2*1e6+5;

int n;
string s;

int tr[MAX][46];
int cnt;
int stop[MAX];

bool add(){
	bool themmoi = false;
	bool quahet = false;
	int u = 0;
	for (char c : s){
		int nc = c - 'a';
		if (tr[u][nc] == 0){
			tr[u][nc] = ++cnt;
			themmoi = true;
		}
		u = tr[u][nc];
		
		if (stop[u] > 0){
			quahet = true;
		}
	}
	stop[u]++;
	
	return quahet || !themmoi;
}

signed main(){
	cin>>n;
	bool isTT = false;
	for (int i=0;i<n;i++){
		cin>>s;
		if(add()){
			isTT = true;
		}
	}
	
	if (isTT){
		cout<<"YES";
	}else{
		cout<<"NO";
	}
}
