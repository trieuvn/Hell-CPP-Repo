#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int M;
    cin >> M;

    if (M == 0) {
        cout << "10" << endl; // N?u M = 0, th� K l� 10
        return 0;
    }

    if (M < 10) {
        cout << M << endl; // N?u M < 10, th� K l� ch�nh s? M
        return 0;
    }

    // T�m K b?ng c�ch b?t d?u t? 9 v� gi?m d?n
    int K = 0;
    for (int i = 9; i >= 2; i--) {
        while (M % i == 0) {
            M /= i;
            K = K * 10 + i;
        }
    }

    // N?u M c�n du l?i sau khi l?p, t?c l� kh�ng th? t?o th�nh K
    if (M != 1) {
        cout << "-1" << endl;
    } else {
        // �?o ngu?c s? K d? c� K nh? nh?t
        int reversedK = 0;
        while (K > 0) {
            reversedK = reversedK * 10 + K % 10;
            K /= 10;
        }

        cout << reversedK << endl;
    }

    return 0;
}
