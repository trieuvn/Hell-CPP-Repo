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
	cin>>S>>T;
	int n = S.length();
	int m = T.length();
	
	int i = 0;
	int j = 0;
	
	int c= 0;
	
	build_lps();
	
	while (i<n){
		if (S[i] == T[j]){
			i++;
			j++;
		}
		if (j == m){
			c++;
			j = lps[j-1];
		}
		else if (S[i] != T[j]){
			if (j != 0){
				j = lps[j-1];
			}else{
				j = 0;
				i++;
			}
		}
	}
	cout<<c;
}
