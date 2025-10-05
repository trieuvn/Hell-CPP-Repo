#include<bits/stdc++.h>
#define int long long

using namespace std;

const int sl = 1e6+5;

char a[sl];
int len;

pair<int, bool> toNum(int l, int r){
	int s = 0;
	for (int i=l;i<=r;i++){
		s = s*10;
		s+= a[i] - '0';
	}
	if (a[l] == '0' && l-r != 0)
		return {s,false};
	return {s,true};
}

pair<int, bool> solve(int x){
	int Min = LLONG_MAX;
	bool stat = false;
	for (int i=x;i<len-1;i++){
		pair<int, bool> l = toNum(x,i);
		pair<int, bool> r = toNum(i+1,len-1);
		if (l.second && r.second){
			Min = min(Min, l.first + r.first);
			stat = true;
		}
	}
	return {Min, stat};
}


signed main(){
	cin>>a;
	len = strlen(a);
	int Min = LLONG_MAX;
	for (int i=0;i<len-1;i++){
		pair<int, bool> temp = solve(i+1);
		if (temp.second){
			Min = min(Min, toNum(0,i).first+temp.first);
			//cout<<toNum(0,i).first<<" "<<temp.first<<"\n";
		}
			//Min = min(Min, toNum(0,i).first+temp.first);
	}
	cout<<Min;
}

