#include<bits/stdc++.h>
#define int long long
 
using namespace std;
 
int a[1000000];
int w[1000000];
vector<int> vec;
 
int bin(int left,int right,int x){
	int mid = (left + right) / 2;
	while (left <= right){
		if (a[vec[mid]] == x){
			return mid;
		}else
		if (x > a[vec[mid]]){
			left = mid +1;
		}else {
			right = mid-1;
		}
		mid = (left + right)/2;
	}
	return left;
}
 
signed main(){
	int n,i,j;
	cin>>n;
	//long a[n+1];
	
	vector<int> lis;
	vector<long> dp(n+1,0);
	vector<int> trace(n+1,-1);
	for (i=0;i<n;i++){
		cin>>a[i];
	}
	for (i=0;i<n;i++){
		cin>>w[i];
	}
	int t;
	long Max=0;
	trace[0] = -1;
	dp[0] = w[0];
	vec.push_back(0);
	for (i=1;i<n;i++){
		for (j=0;j<i;j++){
			if (a[i] > a[j]){
				if (dp[i] < dp[j]+w[i]){
					dp[i] = dp[j]+w[i];
					trace[i] = j;
				}
			}
		}
		if (a[Max] < a[i]){
			Max = i;
		}
	}
	
	for (i=Max;i!=-1;i=trace[i]){
		lis.push_back(i+1);
	}
	cout<<lis.size();
	cout<<"\n";
	reverse(lis.begin(),lis.end());
	for (long k : lis){
		cout<<k<<" ";
	}
}
