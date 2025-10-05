#include <iostream>
#include<math.h>
#include<algorithm>


using namespace std;

int main(){
	int n,i;
	cin>>n;
	int a[n];
	for (i=0;i<n;i++){
		a[i] = i+1;
	}
	do{
		for (i=0;i<n;i++){
			cout<<a[i]<<" ";
		}
		cout<<"\n";
	}while (next_permutation(a,a+n));
}
