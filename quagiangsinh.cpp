#include<bits/stdc++.h>

using namespace std;

const int MAX = 27;

int n,m;
vector<char> gifts;
vector<char> qua[MAX];

int layM(int x){
	return x/2;
}

signed main(){
	cin>>n;
	char gift = 'A';
	for (int i=0;i<n;i++){
		gifts.push_back(gift+i);
	}
	if (n ==1){
		cout<<1<<"\n";
		cout<<'A';
		return 0;
	}
	m = layM(n);
	cout<<m<<"\n";
	int mid = (n-1)/2;
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			int id = (i+2*j)%n;
			char c = id + 'A';
			cout<<c;
		}
		cout<<"\n";
	}
	
	
}
