#include<bits/stdc++.h>
#define int long long
 
using namespace std;
 
int a[1000000];
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
	//vector<long> dp(n+1,1);
	vector<int> trace(n+1,-1);
	for (i=0;i<n;i++){
		cin>>a[i];
	}
	int t;
	//long Max=0;
	trace[0] = -1;
	vec.push_back(0);
	for (i=1;i<n;i++){
		if (a[i] > a[vec.back()]){
			trace[i] = vec.back();
			vec.push_back(i);
			
			//Max = i;
			
		}else{
			t = bin(0,vec.size()-1,a[i]);
			//cout<<i<<" "<<t<<"\n";
			if (t==0)	trace[i] = -1;
			else	trace[i] = vec[t-1];
			vec[t] = i;
			//trace[i] = t;
		}
		
	}
	//for (i=0;i<=n;i++){
		//cout<<vec[i]<<" ";
	//}
	//for (long k : vec){
		//cout<<k<<" ";
	//}
	cout<<vec.size();
	cout<<"\n";
	for (i=vec.back();i!=-1;i=trace[i]){
		lis.push_back(i+1);
	}
	//reverse(lis.begin(),lis.end());
	//for (long k : lis){
		//cout<<k<<" ";
	//}
}
