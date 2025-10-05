#include<string.h>
#include<iostream>

using namespace std;

int main(){
	char a[250];
	int x;
	cin>>a;
	cin>>x;
	char left[250];
	int rightx=strlen(a)-x;
	char right[250];
	int j=strlen(a)-1;
	for (int i=0;i<rightx;i++){
		right[i]=a[j];
		j--;
	}
	char rong[]="\0";
	right[rightx]=rong[0];
	j=x-1;
	for (int i=0;i<x;i++){
		left[i]=a[j];
		j--;
	}
	left[x]=rong[0];
	strcat(left,right);
	cout<<left;
	return 0;
}
