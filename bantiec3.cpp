#include<bits/stdc++.h>

using namespace std;

const int MAX = 5e3+5;

int n,k;
int a[MAX][MAX];
int prefix[MAX][MAX];

int getSum(int xstart, int xend, int ystart, int yend){
	int sum = 0;
	sum = prefix[xend][yend] - prefix[xend][ystart-1] - prefix[xstart-1][yend] + prefix[xstart-1][ystart-1];
	return sum;
	for (int i=xstart;i<=xend;i++){
		for (int j=ystart;j<=yend;j++){
			sum += a[i][j];
		}
	}
	return sum;
}

bool solve(int x){
	x--;
	for (int i=1;i<=n-x;i++){
		for (int j=1;j<=n-x;j++){
			//cout<<i+x;
			if (getSum(i,i+x,j,j+x) < k){
				return false;
			}
		}
	}
	return true;
}

int BS(){
	int left = 1;
	int right = n;
	int mid = (left+right)/2;
	int res=n+1;
	while (left <= right){
		if (solve(mid) == true){
			res = min(res,mid);
			right = mid-1;
		}else{
			left = mid+1;
		}
		mid = (left+right)/2;
	}
	if (res == n+1){
		return -1;
	}
	return res;
}

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			cin>>a[i][j];
			prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + a[i][j];
			//cout<<prefix[i][j]<<" ";
		}
		//cout<<"\n";
	}
	
	cout<<BS();
}
