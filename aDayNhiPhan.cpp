#include<bits/stdc++.h>
#define int long long

using namespace std;

vector<int> num(100001,0);

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,k,i,s,j,cap2;
	cin>>n;
	int a[n+1];
	for (i=0;i<n;i++){
		cin>>a[i];
	}
	//sort(a,a+n);
	int temp = a[0];
	int count = 1;
	for (i=1;i<n;i++){
		if (temp != a[i]){
			num[temp] = count;
			count = 1;
			temp = a[i];
			
		}else
		count++;
	}
	num[temp] = count;
	
	int prefix[100001];
	sort(num.begin(),num.end(),greater<int>());
	//s=(num[0]*(num[0]-1)*(num[0]-2)*(num[0]-3))/24;
	n=1;
	prefix[0] = (num[0]*(num[0]-1))/2;
	for (i=1;i<=num.size();i++){
		if (num[i] == 0)	break;
		prefix[i] = prefix[i-1] + (num[i]*(num[i]-1))/2;
		n++;
		
	}
	s=0;
	s+=(num[0]*(num[0]-1)*(num[0]-2)*(num[0]-3))/24;
	for (i=1;i<=num.size();i++){
		if (num[i] == 0)	break;
		if (num[i] >= 4)
			s+=(num[i]*(num[i]-1)*(num[i]-2)*(num[i]-3))/24;
		s+= prefix[i-1] * (num[i]*(num[i]-1))/2;
	}
	//for (i=0;i<n;i++){
		//cout<<prefix[i]<<" "<<(num[i]*(num[i]-1))/2<<"\n";
	//}
	cout<<s;
}
