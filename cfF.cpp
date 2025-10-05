#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 2*1e5+5;

typedef struct ms{
	int mang[MAX];
	int length = 0;
}ms;

bool compareArray(ms A, ms B){
	for (int i=0;i<A.length && i<B.length;i++){
		if (A.mang[i] < B.mang[i])	return true;
		if (A.mang[i] > B.mang[i])	return false;
	}
	if (A.length < B.length) return true;
	if (A.length >= B.length) return false;
	return false;
}

int t, n, k;
map<ms, int> m;

signed main(){
	cin>>t;
	while(t--){
		cin>>n;
		int max_length = 0;
		for (int i=0;i<n;i++){
			cin>>k;
			m[i].length = k;
			for (int j=0;j<k;j++){
				cin>>m[i].mang[j];
			}
			max_length = max(max_length, k);
		}
		
		sort(m, m+n,compareArray);
		
		for (int i=0;i<n;i++){
			int j = 0;
			while (j < max_length){
				for (int u=)
			}
		}
	}
	
}
