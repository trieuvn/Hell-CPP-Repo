#include <iostream>
using namespace std;

int n;
long long k;
long long a[20]; // M?ng tinh ch?a t?i da 20 ph?n t?
long long count = 0;

// H�m quay lui
void backtrack(int i, long long sum) {
    // N?u d� duy?t h?t d�y s?
    if (i == n) {
        // Ki?m tra n?u t?ng b?ng k
        if (sum == k) {
            count++;
        }
        return;
    }

    // L?a ch?n 1: Kh�ng ch?n ph?n t? th? i
    backtrack(i + 1, sum);

    // L?a ch?n 2: Ch?n ph?n t? th? i
    backtrack(i + 1, sum + a[i]);
}

int main() {
    cin >> n >> k;

    // Nh?p d�y s?
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // G?i h�m quay lui b?t d?u t? ch? s? 0 v� t?ng ban d?u l� 0
    backtrack(0, 0);

    // Xu?t k?t qu?
    cout << count << endl;

    return 0;
}
