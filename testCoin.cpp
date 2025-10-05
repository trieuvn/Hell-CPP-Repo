#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;

int n, X;
vector<int> coins;
vector<vector<int>> dp; // Luu tr? tr?ng thái (memoization)

// Hàm quay lui v?i DP
int solve(int currentSum, int index) {
    // N?u dã tính tr?ng thái này, tr? v? ngay
    if (dp[currentSum][index] != -1) {
        return dp[currentSum][index];
    }

    // Co s? d?ng
    if (currentSum == X) return 1;           // Ð?t du?c t?ng mong mu?n
    if (currentSum > X || index >= n) return 0; // Vu?t quá t?ng ho?c h?t d?ng xu

    // Tính toán s? cách
    int ways = 0;
    
    // Ch?n d?ng xu hi?n t?i (cho phép ch?n l?i)
    ways = (ways + solve(currentSum + coins[index], index)) % MOD;
    
    // B? qua d?ng xu hi?n t?i, chuy?n sang d?ng xu ti?p theo
    ways = (ways + solve(currentSum, index + 1)) % MOD;

    // Luu k?t qu? vào dp và tr? v?
    return dp[currentSum][index] = ways;
}

signed main() {
    cin >> n >> X;
    coins.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    // Kh?i t?o dp v?i giá tr? -1 (chua tính)
    dp.assign(X + 1, vector<int>(n + 1, -1));

    // G?i hàm gi?i
    cout << solve(0, 0) << endl;
    return 0;
}

