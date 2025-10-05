#include<bits/stdc++.h>
using namespace std;

const long INF = -1e18; // Gi� tr? t?i thi?u d? so s�nh trong qu� tr�nh t�m max
long dp[101][101][501]; // B?ng nh?: dp[left][right][k]
long a[1001]; // M?ng ch?a gi� tr? c�c th?

// H�m gi?i quy?t b�i to�n v?i quy ho?ch d?ng
long solve(int left, int right, int k) {
    // N?u d� ch?n d? k c?p th?, tr? v? t?ng hi?n t?i (0 v� d� ho�n th�nh)
    if (k == 0) return 0;

    // N?u kh�ng d? th? d? ch?n k c?p th?, tr? v? gi� tr? t?i thi?u
    if (right - left + 1 < 2 * k) return INF;

    // N?u tr?ng th�i d� du?c t�nh to�n tru?c, tr? v? gi� tr? luu tr?
    if (dp[left][right][k] != INF) return dp[left][right][k];

    // T�nh to�n gi� tr? l?n nh?t c� th? d?t du?c t? 3 l?a ch?n:
    long result = INF;

    // Ch?n th? d?u v� th? cu?i, sau d� thu h?p ph?m vi
    result = max(result, abs(a[left] - a[right]) + solve(left + 1, right - 1, k - 1));

    // Ch?n 2 th? d?u ti�n, sau d� lo?i b? 2 th? d?u
    result = max(result, abs(a[left] - a[left + 1]) + solve(left + 2, right, k - 1));

    // Ch?n 2 th? cu?i c�ng, sau d� lo?i b? 2 th? cu?i
    result = max(result, abs(a[right] - a[right - 1]) + solve(left, right - 2, k - 1));

    // Luu k?t qu? t�nh to�n v�o b?ng nh? dp
    dp[left][right][k] = result;

    return result;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;

    // �?c gi� tr? c�c th?
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Kh?i t?o b?ng nh? dp v?i gi� tr? INF (chua t�nh to�n)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int t = 0; t <= k; t++) {
                dp[i][j][t] = INF;
            }
        }
    }

    // G?i h�m gi?i quy?t v� in k?t qu?
    cout << solve(0, n - 1, k) << endl;

    return 0;
}
