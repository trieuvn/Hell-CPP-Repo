#include<bits/stdc++.h>
using namespace std;

const long INF = -1e18; // Giá tr? t?i thi?u d? so sánh trong quá trình tìm max
long dp[101][101][501]; // B?ng nh?: dp[left][right][k]
long a[1001]; // M?ng ch?a giá tr? các th?

// Hàm gi?i quy?t bài toán v?i quy ho?ch d?ng
long solve(int left, int right, int k) {
    // N?u dã ch?n d? k c?p th?, tr? v? t?ng hi?n t?i (0 vì dã hoàn thành)
    if (k == 0) return 0;

    // N?u không d? th? d? ch?n k c?p th?, tr? v? giá tr? t?i thi?u
    if (right - left + 1 < 2 * k) return INF;

    // N?u tr?ng thái dã du?c tính toán tru?c, tr? v? giá tr? luu tr?
    if (dp[left][right][k] != INF) return dp[left][right][k];

    // Tính toán giá tr? l?n nh?t có th? d?t du?c t? 3 l?a ch?n:
    long result = INF;

    // Ch?n th? d?u và th? cu?i, sau dó thu h?p ph?m vi
    result = max(result, abs(a[left] - a[right]) + solve(left + 1, right - 1, k - 1));

    // Ch?n 2 th? d?u tiên, sau dó lo?i b? 2 th? d?u
    result = max(result, abs(a[left] - a[left + 1]) + solve(left + 2, right, k - 1));

    // Ch?n 2 th? cu?i cùng, sau dó lo?i b? 2 th? cu?i
    result = max(result, abs(a[right] - a[right - 1]) + solve(left, right - 2, k - 1));

    // Luu k?t qu? tính toán vào b?ng nh? dp
    dp[left][right][k] = result;

    return result;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;

    // Ð?c giá tr? các th?
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Kh?i t?o b?ng nh? dp v?i giá tr? INF (chua tính toán)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int t = 0; t <= k; t++) {
                dp[i][j][t] = INF;
            }
        }
    }

    // G?i hàm gi?i quy?t và in k?t qu?
    cout << solve(0, n - 1, k) << endl;

    return 0;
}
