#include <bits/stdc++.h> // �? s? d?ng int64_t (ho?c d�ng long long)

using namespace std;

int main() {
    // Tang t?c d? nh?p xu?t
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    // B?t bu?c d�ng int64_t
    vector<int64_t> a(n), b(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    // Kh?i t?o k?t qu? t?t nh?t v?i c?p d?u ti�n (0, 1)
    int64_t best_A = a[0] + a[1];
    int64_t best_B = b[0] + b[1];

    // B?t d?u duy?t tr�u O(N^2)
    // V�ng l?p i t? 0 d?n n-2
    for (int i = 0; i < n; ++i) {
        // V�ng l?p j t? i+1 d?n n-1
        // d? d?m b?o ta ch? x�t m?i c?p 1 l?n v� i != j
        for (int j = i + 1; j < n; ++j) {
            
            int64_t current_A = a[i] + a[j];
            int64_t current_B = b[i] + b[j];

            // So s�nh t? l? (current_B / current_A) v?i (best_B / best_A)
            // D�ng ph�p nh�n ch�o int64_t d? tr�nh sai s?
            // v� tr�nh tr�n s? (v� 2*10^9 * 2*10^9 = 4*10^18, v?a d? cho int64_t)

            if (current_B * best_A < best_B * current_A) {
                // T? l? m?i t?t hon (nh? hon)
                best_A = current_A;
                best_B = current_B;
            } else if (current_B * best_A == best_B * current_A) {
                // T? l? b?ng nhau, ki?m tra di?u ki?n ph?
                // Uu ti�n t?ng s? th�nh ph? (A) l?n hon
                if (current_A > best_A) {
                    best_A = current_A;
                    best_B = current_B;
                }
            }
        }
    }

    // In ra k?t qu?
    cout << best_A << " " << best_B << "\n";

    return 0;
}
