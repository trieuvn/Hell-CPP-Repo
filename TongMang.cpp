#include<bits/stdc++.h>
#include<string.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
	unsigned long long x;
	unsigned int n;
	cin>>n;
	unsigned long long tong=0;
	for (int i=0;i<n;i++){
		cin>>x;
		tong+=x;
	}
	cout<<tong;
	return 0;
}
