#include <iostream>
#include<math.h>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

typedef struct vt{
	int u;
	int v;
};

int a[1001][1001];
long visit[1001][1001];
int m,n;

long bfs(int u, int v){
	long Max = 1;
	stack<vt> q;
	vt x;
	x.u = u;
	x.v = v;
	visit[u][v] = 1;
	q.push(x);
	while (!q.empty()){
		x = q.top();
		q.pop();
		
		for (int i=-4;i<=4;i++){
			int d = x.u+i;
			if (d < 1)	continue;
			if (d > m)	break;
			for (int j=-4;j<=4;j++){
				int c = x.v+j;
				if (c < 1)	continue;
				if (c > n)	break;
				if (a[d][c] != 1)	continue;
				if (visit[d][c] == -1){
					visit[d][c] = visit[x.u][x.v] + 1;
					Max = max(Max,visit[d][c]);
					vt k;
					k.u = d;
					k.v = c;
					q.push(k);
				}else{
					visit[d][c] = visit[d][c]+1;
					Max = max(Max,visit[d][c]);
					/*vt k;
					k.u = d;
					k.v = c;
					q.push(k);*/
				}
			}
		}
	}
}

int main(){
	int u,v,i,j;
	cin>>m>>n>>u>>v;
	for (i=1;i<=m;i++){
		for (j=1;j<=n;j++){
			cin>>a[i][j];
			visit[i][j]=-1;
		}
	}
	//cout<<bfs(u,v);
	bfs(u,v);
	for (i=1;i<=m;i++){
		for (j=1;j<=n;j++){
			cout<<visit[i][j]<<" ";
		}
		cout<<"\n";
	}
}
