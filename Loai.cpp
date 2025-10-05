#include<bits/stdc++.h>

using namespace std;

int main(){
	//ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	int r[12]= {0,0,0,0,0,0,0,0,0,0,0,0};
	int res[12];
	int x;
	int dem=0;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>x;
		r[x]++;
		if (r[x]% 3 == 0){
			res[dem]=x;
			dem++;
		}
	}
	cout<<dem;
	if (dem > 0){
		cout<<"\n";
	}
	for (int i=0;i<dem;i++){
		cout<<res[i]<<" ";
	}
	return 0;
}
