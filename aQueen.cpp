#include<bits/stdc++.h>
#define int int64_t

using namespace std;

int n;
bool col[30];
bool dcc[30];
bool dcp[30];

int solve(int x, int y, int sl){
	if (sl == n){
		return 1;
	}	
	int s = 0;
	for (int i=x+1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (col[j] == false && dcc[i+j] == false && dcp[i-j+n] == false){
				col[j] = true;
				dcc[j+i] = true;
				dcp[i-j+n] = true;
				s += solve(i,j,sl+1);
				col[j] = false;
				dcc[j+i] = false;
				dcp[i-j+n] = false;
			}
		}
	}
	
	return s;
}

signed main(){
	cin>>n;
	int s = 0;
	for (int i=1;i<=n;i++){
		col[i] = true;
		dcc[1+i] = true;
		dcp[1-i+n] = true;
		s += solve(1,i,1);
		col[i] = false;
		dcc[1+i] = false;
		dcp[1-i+n] = false;
	}
	cout<<s;
	//showLock();
}
