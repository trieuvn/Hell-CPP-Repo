#include <iostream>
using namespace std;

int main () {
    long long n,k,res;
    cin >> n >> k;
    if (n <= k)
        {
            cout << "10";
            exit(0);
        }
    n = n * 2;
    res = n / k;
    if ( (n % k) != 0 )
        {
            res = res + 1;
        }
    cout << res*5;
}
