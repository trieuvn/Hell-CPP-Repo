#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1e5+5;

int n;
int a[MAX];
map<int,int> mark;

signed main(){
	cin>>n;
	int Max = 0;
	int MaxNum = LLONG_MAX;
	for (int i=0;i<n;i++){
		cin>>a[i];
		mark[a[i]]++;
		if (mark[a[i]] >= Max){
			if (mark[a[i]] == Max){
				MaxNum = min(MaxNum, a[i]);
			}else{
				MaxNum = a[i];
			}
			Max = mark[a[i]];
			
		}
	}
	cout<<MaxNum;
	
}
