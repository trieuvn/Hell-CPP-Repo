#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1e6+5;

int n;
int ox[MAX];
int oy[MAX];
pair<int,int> xl[MAX];
pair<int,int> yl[MAX];
set<pair<int,int>> candidates;
vector<int> dist;

signed main(){
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>ox[i]>>oy[i];
		xl[i] = {ox[i],i};
		yl[i] = {oy[i],i};
	}
	
	sort(xl,xl+n);
	sort(yl,yl+n);
	
    candidates.insert({min(xl[0].second, xl[n-1].second), max(xl[0].second, xl[n-1].second)});
    candidates.insert({min(xl[0].second, xl[n-2].second), max(xl[0].second, xl[n-2].second)});
    candidates.insert({min(xl[1].second, xl[n-1].second), max(xl[1].second, xl[n-1].second)});
    
    candidates.insert({min(yl[0].second, yl[n-1].second), max(yl[0].second, yl[n-1].second)});
    candidates.insert({min(yl[0].second, yl[n-2].second), max(yl[0].second, yl[n-2].second)});
    candidates.insert({min(yl[1].second, yl[n-1].second), max(yl[1].second, yl[n-1].second)});
	
	for (pair<int,int> c : candidates){
		int dx = abs(ox[c.first] - ox[c.second]);
		int dy = abs(oy[c.first] - oy[c.second]);
		dist.push_back(max(dx,dy));
	}
	
	sort(dist.rbegin(), dist.rend());
	
	cout<<dist[1];
}
