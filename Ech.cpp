#include<stdio.h>
#include<math.h>
#include<iostream>

using namespace std;

int Buoc(int a[], int i){
	int b=abs(a[i]-a[i+1]);
	return b;
}

int Nhay(int a[], int i){
	int n=abs(a[i]-a[i+2]);
	return n;
}


int main(){
	int n, a[100];
	int i=0;
	int res;
	int sb;
	cin>>n;
	a[1]=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<2){
		cout<<abs(a[0]-a[1]);
		return 0;
	}
	else if(n==3){
		cout<<abs(a[0]-a[2]);
		return 0;
	}
	else if(n%2!=0){
		res=Buoc(a,0)+Buoc(a,n-2);
		for (int i=1;i<n-3;i+=2){
			res+=Nhay(a,i);
		}
		int test=0;
		for (int i=0;i<n-2;i+=2){
			test+=Nhay(a,i);
		}
		if (res<test){
			cout<<res;
			return 0;
		}
		else{
			cout<<test;
			return 0;
		}
	}
	else
	return 0;
}
