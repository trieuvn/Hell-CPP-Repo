#include<bits/stdc++.h>
#include<string.h>

using namespace std;
int main(){
	unsigned long m,t;
	unsigned long long n;
	unsigned long long s;
	cin>>m>>n>>t;
	unsigned long them=n/(m+1);
	s=(n-them)*t;
	cout<<s;
	
	return 0;
}
