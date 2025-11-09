#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1e6+5;

string S, T;
int lps[MAX];

void build_lps(){
	int i = 1;
	int len = 0;
	int m = T.length();
	while (i < m){
		if (T[i] == T[len]){
			len++;
			lps[i] = len;
			i++;
		}else{
			if (len != 0){
				len = lps[len-1];
			}else{
				lps[i] = 0;
				i++;
			}
		}
	}
}

signed main(){
	cin>>T;
	int n = T.length();
	
	build_lps();
	
	int rot = n - lps[n-1];
	
	string news = "";
	for (int i=0;i<rot;i++){
		news+=T[i];
	}
	//cout<<temp;
	cout<<news;
}
