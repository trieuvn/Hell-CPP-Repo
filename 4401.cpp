#include <iostream>
using namespace std;

long long Fibo(long long n) {//29  11 2
	long long kq=n;
    while (n >= 10){
    	kq=0;
    	while (n != 0){
    		kq+=n%10;
    		n=n/10;
		}
		n=kq;
	}
	return kq;
}

int main() {
    char n[1000000];

    /*for (unsigned int i=1000;i<100000;i++){
		
    	unsigned int result = Fibo(i);
    	cout << result;
    	cout << "\n";
    }*/
    cin >> n;
	long long result = Fibo(n);
    cout << result;
    return 0;
}
