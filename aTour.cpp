#include <bits/stdc++.h> // Ð? s? d?ng int64_t (ho?c dùng long long)

using namespace std;

int main() {
    // Tang t?c d? nh?p xu?t
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    // B?t bu?c dùng int64_t
    vector<int64_t> a(n), b(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    // Kh?i t?o k?t qu? t?t nh?t v?i c?p d?u tiên (0, 1)
    int64_t best_A = a[0] + a[1];
    int64_t best_B = b[0] + b[1];

    // B?t d?u duy?t trâu O(N^2)
    // Vòng l?p i t? 0 d?n n-2
    for (int i = 0; i < n; ++i) {
        // Vòng l?p j t? i+1 d?n n-1
        // d? d?m b?o ta ch? xét m?i c?p 1 l?n và i != j
        for (int j = i + 1; j < n; ++j) {
            
            int64_t current_A = a[i] + a[j];
            int64_t current_B = b[i] + b[j];

            // So sánh t? l? (current_B / current_A) v?i (best_B / best_A)
            // Dùng phép nhân chéo int64_t d? tránh sai s?
            // và tránh tràn s? (vì 2*10^9 * 2*10^9 = 4*10^18, v?a d? cho int64_t)

            if (current_B * best_A < best_B * current_A) {
                // T? l? m?i t?t hon (nh? hon)
                best_A = current_A;
                best_B = current_B;
            } else if (current_B * best_A == best_B * current_A) {
                // T? l? b?ng nhau, ki?m tra di?u ki?n ph?
                // Uu tiên t?ng s? thành ph? (A) l?n hon
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
