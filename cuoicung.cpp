#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    long long a;
    unsigned long long s=0;
    unsigned long dem=0;
    for (int i=0;i<n;i++){
    	cin>>a;
    	if (dem+1<a){
    		a-=dem;
    		s+=a;
    		dem++;
		}
	}
	cout<<s;
    
    return 0;
}






/*
0
0 0
0 0 0
0 0 0 0
0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
3 6 10 15 21 28 36 45 55 66 78
*/
