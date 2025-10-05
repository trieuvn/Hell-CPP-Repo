#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,m,dem=0;
	cin>>n>>m;
	if (n==0 && m==1){
		cout<<"0";
		return 0;
	}
	vector <int> a(n);
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a.rbegin(),a.rend());
	a[0]=a[0]+1;
	for (int i=0;i<n;i++){
		if (m > 0){
			m-=(a[i]-1);
			dem++;
		}
	}
	if (m<=0)	cout<<dem;
	else cout<<-1;
	return 0;
}
