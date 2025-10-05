#include<bits/stdc++.h>
#include <vector>

using namespace std;
int main(){
	long n,m,dem;
	dem=0;
	cin>>n>>m;
	vector<long> a;
	vector<long> b;
	long x;
	for (long i=0;i<n;i++){
		cin>>x;
		a.push_back(x);
	}
	for (long i=0;i<m;i++){
		cin>>x;
		b.push_back(x);
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());

	long left=0;
	long right=n+1;
	for (long i=0;i<n;i++){
		if (b[0] < a[i]){
			left = i;
			a[i]=0;
			break;
		}
	}
	for (long i=n;i>=0;i--){
		if (b[m-1] < a[i]){
			right =i;
			break;
		}
	}
	cout<<left;
	cout<<right;
	cout<<left-right;

	/*for (long i=0;i<m;i++){
		sort(a.begin(),a.end());
		if (b[i] >= a[n-1])	continue;
		for (long j=0;j<n;j++){
			if (b[i] < a[j]){
				a[j] = 0;
				dem++;
				break;
			}
				
		}
	}
	

	cout<<dem;*/
}
