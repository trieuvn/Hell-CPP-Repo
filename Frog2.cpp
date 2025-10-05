#include<stdio.h>
#include<math.h>
#include<iostream>

using namespace std;


int main(){
	int n, k;
	int h[1001];
	int pd[1001];
	cin>>n;
	cin>>k;
	for (int i=0;i<n;i++){
		cin>>h[i];
	}
	pd[0]=0;
	for (int i=1;i<n;i++){
		pd[i]=pd[i-1]+abs(h[i-1]-h[i]);
		for (int j=1;j<=k && i>=j;j++){
			pd[i]=min(pd[i],pd[i-j]+abs(h[i-j]-h[i]));
		}
	}
	cout<<pd[n-1];
	return 0;
}
