#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<math.h>

using namespace std;

int KT(char a[], int left,int right){
	for (int i=left;i<right;i++){
		if (a[i]==a[right])
			return 1;
	}
	return 0;
}

int main(){
	char a[50000]; 
	cin>>a;
	int dem;
	int kq=0;
	for (int i=0;i<=strlen(a);i++){
		dem=0;
		for (int j=i;j<strlen(a);j++){
			if (KT(a,i,j)==1)
				break;
			else 
				dem++;
		}
		if (kq<dem)
			kq=dem;
	}
	cout<<kq;
	return 0;
}
