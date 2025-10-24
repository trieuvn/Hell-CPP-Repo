#include<bits/stdc++.h>
#define int long long

using namespace std;
const int MAX = 1e6+5;

int n,m,c;
int a[MAX];
multiset<int> block;
vector<int> res;

signed main(){
	cin>>n>>m>>c;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	//init
	for (int i=1;i<=m;i++){
		block.insert(a[i]);
	}
	auto left = block.begin();
	auto right = block.end();
	right--;
	if (abs(*left - *right) <= c){
		res.push_back(1);
	}
	//loop
	int j = 1;
	for (int i=m+1;i<=n;i++){
		block.erase(block.find(a[j]));
		j++;
		block.insert(a[i]);
		auto left = block.begin();
		auto right = block.end();
		right--;
		if (abs(*left - *right) <= c){
			res.push_back(j);
		}
	}
	if (res.size() == 0){
		cout<<"NONE";
		return 0;
	}
	for (int k : res){
		cout<<k<<"\n";
	}
}
