#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<stdio.h>
#include<vector>

using namespace std;

typedef struct canh{
	int des;
	int d;
};

int n,m;
vector<canh> vec[20000];
int h[10001];
int unVisit[10001];


int prim(int u, int des, int n){
	vector<int> mst;
	mst.push_back(u);
	unVisit[u] = 0;
	int d=INT_MIN;
	int count = 0;
	int Min;
	int cMin;
	while (count != n-1){
		count++;
		Min = INT_MAX;
		for (int i : mst){
			//cout<<i<<" ";
			for (canh j : vec[i]){
				if (unVisit[j.des] == 0) continue;
				if (j.d < Min){
					//cout<<j.d<<" ";
					Min = j.d;
					cMin = j.des;
				}
			}
		}
		//cout<<"\n";
		mst.push_back(cMin);
		d = max(d,Min);
		//cout<<d<<" ";
		if (cMin == des)	return d;
		unVisit[cMin] = 0;
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int s,t,i,j,u,v;
	cin>>m>>n>>s>>t;
	fill(unVisit,unVisit+n+1,1);
	for (i=1;i<=m;i++){
		cin>>h[i];
	}
	for (i=0;i<n;i++){
		cin>>u;
		cin>>v;
		int d = abs(h[u]-h[v]);
		vec[u].push_back({v,d});
		
		vec[v].push_back({u,d});
		//cout<<c.d<<" ";
	}
	cout<<prim(s,t,m);
	
}
