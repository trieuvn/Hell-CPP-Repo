#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>
#include<stdio.h>

using namespace std;

int main(){
	long n,k,i,j;
	cin>>n>>k;
	long h[n],d[n];
	long long s=0;
	for (i=0;i<n;i++){
		cin>>h[i];
	}
	sort(h,h+n,greater<long>());
	for (i=0;i<k;i++){
		cin>>d[i];
	}
	sort(d,d+k);
	
	i=0;
	while (n>0){
		if (i==k){
			cout<<s;
			return 0;
		}
		if (d[i] < h[n-1]){
			s+=h[n-1];
			n--;
			i++;
		}else{
			n--;
		}
	}
	
	if (i==k){
		cout<<s;
		return 0;
	}
	else{
		cout<<"No";
		return 0;
	}
	cout<<s;
}
