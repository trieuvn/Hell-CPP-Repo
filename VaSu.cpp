#include<bits/stdc++.h>

using namespace std;

int main(){
	//ios_base::sync_with_stdio(false);	cin.tie(0);	cout.tie(0);
	int n;
	cin>>n;
	vector <int> a(n);
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a.rbegin(),a.rend());
	unsigned long long s=0;
	int scare=0;
	for (int i=0;i<n;i++){
		if (a[i]-scare > 0){
			s+=a[i]-scare;
			scare++;
		}
	}
	cout<<s;
	return 0;
}
