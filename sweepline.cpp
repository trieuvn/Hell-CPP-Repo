#include<bits/stdc++.h>

using namespace std;

const int MAX = 2e5+5;

typedef struct Point{
	int x1;
	int x2;
	int y1;
	int y2;
}Point;

int n;
Point p[MAX];

bool cmp(Point a, Point b){
	if (a.x1 == b.x1){
		if (a.y1 == b.y1){
			if (a.x2 == b.x2){
				return a.y2 < b.y2;
			}
			return a.x2 < b.x2;
		}
		return a.y1 < b.y1;
	}
	return a.x1 < b.x1;
}

signed main(){
	cin>>n;
	for (int i=0;i<n;i++){
		int x1,x2,y1,y2;
		cin>>x1>>y1>>x2>>y2;
		p[i].x1 = x1;
		p[i].y1 = y1;
		p[i].x2 = x2;
		p[i].y2 = y2;
	}
	
	sort(p,p+n,cmp);
	int endx = 1e5;
	int j = 0;
	
	set<pair<pair<int,int>, pair<int,int>>> s;
	
	for (int sweep=1;sweep<=endx;sweep++){
		while (sweep == p[j].x1 && j < n){
			s.insert({{p[j].x2,p[j].y2},{p[j].x1,p[j].y1}});
			j++;
		}
		auto it = s.begin();
		while (!s.empty() && (*it).first.first < sweep){
			s.erase(it);
			it = s.begin();
		}
	}
}
