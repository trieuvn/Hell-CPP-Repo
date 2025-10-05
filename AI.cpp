#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    long long count = 0;

    // Ki?m tra v?i 2 l� s? nguy�n t? nh? nh?t
    while (n % 2 == 0) {
        count++;
        n /= 2;
    }

    // Ki?m tra v?i c�c s? l? t? 3 tr? di
    for (long long i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            count++;
            n /= i;
        }
    }

    // N?u n l?n hon 1 th� n� l� m?t s? nguy�n t?
    if (n > 1) {
        count++;
    }

    cout << count << endl;

    return 0;
}
