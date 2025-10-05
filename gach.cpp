#include<bits/stdc++.h>

using namespace std;

int main(){
	vector <int> a(101);
	int x;
	int n;
	int dem=0;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i];		
	}
	sort(a.rbegin(),a.rend());
	int sl=1;
	for (int i=0;i<n;i++){
		for (int j=0;j<i;j++){
			if (a[j]-i+j<0){
				sl=0;
				break;
				
			}
		}
		if (sl==0){
			break;
		}
		dem++;
	}
	cout<<dem;
	return 0;
}
