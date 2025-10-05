#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,i,j,count=1,Max=INT_MIN,k;
	cin>>n;
	long a[n],b[n];
	for (i=0;i<n;i++){
		cin>>a[i];
	}
	for (i=0;i<n;i++){
		cin>>b[i];
	}
	for (i=0;i<n;i++){
		count = 1;
		for (j=0;j<n;j++){
			if (a[i] == b[j]){
				long nhay = 1;
				while (nhay <n){
					count = 1;
					for (k=nhay;j+k<n;k+=nhay){				
						if (a[i+k] == b[j+k]){
							count++;
							continue;
						}else{
							Max= max(Max,count);
							nhay++;
							break;
						}
					}
					nhay++;
				}
			}
		}
	}
	cout<<Max;
}
