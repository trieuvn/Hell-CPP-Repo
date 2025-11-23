#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1e6+5;

int n,q;
int x[MAX];
int y[MAX];
int px[MAX];
int py[MAX];

void preprocess(){
	sort(x,x+n);
	sort(y,y+n);
	for (int i=0;i<n;i++){
		px[i+1] = px[i] + x[i];
	}
	for (int i=0;i<n;i++){
		py[i+1] = py[i] + y[i];
	}
}

int get(int tx, int ty){
	int sum = 0;
	int itx = lower_bound(x,x+n,tx) - x;
	int left = 2*abs(itx*tx - px[itx]);
	int right = 2*abs((n-itx)*tx - (px[n] - px[itx]));
	sum += left+right;
	//cout<<left<<" ";
	int ity = lower_bound(y,y+n,ty) - y;
	left = 2*abs(ity*ty - py[ity]);
	right = 2*abs((n-ity)*ty - (py[n] - py[ity]));
	sum += left+right;
	
	return sum;
}

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>x[i];
		cin>>y[i];
	}
	
	preprocess();
	
	cin>>q;
	for (int i=0;i<q;i++){
		int qx,qy;
		cin>>qx>>qy;
		cout<<get(qx,qy)<<"\n";
	}
	
}
