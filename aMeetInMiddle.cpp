#include<bits/stdc++.h>
#define int long long

using namespace std;

int n,k;
int arr[45];

vector<int> left_sums;
vector<int> right_sums;

void generate_sums(vector<int> &sums, int start, int end){
	int len = end - start +1;
	for (int mask=0;mask < (1 << len);mask++){
		//cout<<bitset<20>(mask)<<" ";
		int sum = 0;
		for (int i=0;i<len;i++){
			if (mask & (1 << i)){
				sum+=arr[start+i];
			}
		}
		sums.push_back(sum);
	}
	sort(sums.begin(), sums.end());
}

signed main(){
	cin>>n>>k;
	for (int i=0;i<n;i++){
		cin>>arr[i];
	}
	int mid = n/2;
	generate_sums(left_sums,0,mid-1);
	generate_sums(right_sums,mid,n-1);
	
	for (int s : right_sums){
		int res = lower_bound(left_sums.begin(), left_sums.end(), k-s) - left_sums.begin();
		if (left_sums[res] == k-s){
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";
	
}
