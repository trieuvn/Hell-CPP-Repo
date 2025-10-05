#include<iostream>
#include<math.h>

using namespace std;

int main(){
	unsigned int x;
	cin>>x;
	int dem=0;
	for (unsigned int i=5;i<=x;i*=5){
		dem+=x/i;
	}
	cout<<dem;
	return 0;
}
