#include<bits/stdc++.h>
#define int long long

using namespace std;

map <pair<int, int>, bool> vis;

int bfs(int x, int y, int m){
	if (x >= m || y >= m)	return 0;
	
	if (x <= 0 && y <= 0)	return -1;
	
	int s = 0;
	while (x <m && y<m){
		if (x>y)	swap(x,y);
		
		if (x < 0){
			int i = abs(x) / y +1;
			x += i*y;
			s += i;
		}else{
			x+=y;
			s++;
		}
	}
	return s;
}

signed main(){
	int x,y,m;
	cin>>x>>y>>m;
	
	cout<<bfs(x,y,m);
}
