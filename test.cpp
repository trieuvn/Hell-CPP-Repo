#include<bits/stdc++.h>
#define int long

using namespace std;
const int sl = 2*1e5+5;

int n,q;
char s[sl];
int len;
vector<bool> mark(sl,false);
int res;

bool chk(int l){
	if (l<0 || l+3 >= len) return false;
	if (s[l] == '1' && s[l+1] == '1' && s[l+2] == '0'&& s[l+3] == '0'){
		return true;
	}
	return false;
}

int count(){
	int res = 0;
	for (int i=0;i<len-4;i++){
		if (chk(i) == true){
			res++;
			mark[i] = true;
			mark[i+1] = true;
			mark[i+2] = true;
			mark[i+3] = true;
		}
			
	}
	return res;
}

void lim(int x){
	if (mark[x] == true)
		for (int i=x-3;i<=x;i++){
			if (chk(i) == true){
				res--;
				mark[i] = false;
				mark[i+1] = false;
				mark[i+2] = false;
				mark[i+3] = false;
				break;
			}
		}
	
	if (s[x] == '0') s[x] = '1';
	else s[x] = '0';
	
	for (int i=x-3;i<=x;i++){
		if (chk(i) == true){
			res++;
			mark[i] = true;
			mark[i+1] = true;
			mark[i+2] = true;
			mark[i+3] = true;
			break;
		}
	}
}

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>len>>q;
	cin>>s;
	//cout<<count()<<"\n";
	res = count();
	for (int i=0;i<q;i++){
		int t;
		cin>>t;
		lim(t-1);
		cout<<res<<"\n";
	}
}
