#include<bits/stdc++.h>

using namespace std;

const long INF = -1e18;
long a[1001];
long dp[201][201][301]; 

long Test(long left, long right, long k){
	if (k == 0){
		//cout<<left<<" "<<right<<" "<<s<<"\n";
		return 0;
	}
	
	if (right - left + 1 < 2 * k) return INF;
	if (dp[left][right][k] != INF) return dp[left][right][k];
	long Max = INF;
	Max = max(Max, abs(a[left] - a[right]) + Test(left + 1, right - 1, k - 1));
	Max = max(Max, abs(a[left] - a[left + 1]) + Test(left + 2, right, k - 1));
	Max = max(Max, abs(a[right] - a[right - 1]) + Test(left, right - 2, k - 1));
	dp[left][right][k] = Max;
	return Max;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	long n,i,j,k;
	cin>>n>>k;
	for (i=0;i<n;i++){
		cin>>a[i];
	}
	for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int t = 0; t <= k; t++) {
                dp[i][j][t] = INF;
            }
        }
    }
	cout<<Test(0,n-1,k);
}
