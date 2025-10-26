#include<bits/stdc++.h>

using namespace std;
const int MAX = 1e5+5;

int n;
int a[MAX];

signed main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	int Max = 0;
	int j = 1;
	for (int i=1;i<=n;i++){
		int size = i-j+1;
		while (a[i] - size < 0){
			j++;
			size = i-j+1;
		}
		Max = max(Max, size);
	}
	cout<<Max;
}
