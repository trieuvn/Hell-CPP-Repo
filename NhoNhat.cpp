#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int M;
    cin >> M;

    if (M == 0) {
        cout << "10" << endl; // N?u M = 0, thì K là 10
        return 0;
    }

    if (M < 10) {
        cout << M << endl; // N?u M < 10, thì K là chính s? M
        return 0;
    }

    // Tìm K b?ng cách b?t d?u t? 9 và gi?m d?n
    int K = 0;
    for (int i = 9; i >= 2; i--) {
        while (M % i == 0) {
            M /= i;
            K = K * 10 + i;
        }
    }

    // N?u M còn du l?i sau khi l?p, t?c là không th? t?o thành K
    if (M != 1) {
        cout << "-1" << endl;
    } else {
        // Ð?o ngu?c s? K d? có K nh? nh?t
        int reversedK = 0;
        while (K > 0) {
            reversedK = reversedK * 10 + K % 10;
            K /= 10;
        }

        cout << reversedK << endl;
    }

    return 0;
}
