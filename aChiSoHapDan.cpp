#include<bits/stdc++.h>
#define int long long

using namespace std;

char c[100001];
int dp[100001][100001];

int genNum(int l, int r){
	int temp=0;
	int i;
	
	for (i=l-1;i<r;i++){
		temp = temp * 10 + (c[i]-'0');
	}
	return temp;
}

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int q;
	cin>>q>>c;
	int t,l,r,i,j,m,count;
	int prefix[100001];
	int len = strlen(c);
	prefix[0] = 0;
	
	//cout<<genNum(1,5);
	cin>>t;
	for (i=0;i<len;i++){
		if (genNum())
		prefix[i+1] = prefix[i] + (c[i] - '0');
	}
	for (i=0;i<=len;i++){
		cout<<prefix[i]<<" ";
	}
	for (i=0;i<t;i++){
		count = 0;
		cin>>l>>r;
		for (j=1;j<=len;j++){
			for (m=1;m<=len;m++){
				if (genNum(j,m)%q == 0)	count++;
			}
		}
		cout<<count<<"\n";
	}
	for (i=0;i<t;i++){
		count = 0;
		cin>>l>>r;
		for (j=l;j<=r;j++){
			for (m=j;m<=r;m++){
				if (genNum(j,m)%q == 0)	count++;
			}
		}
		cout<<count<<"\n";
	}
}
