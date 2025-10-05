#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;

int main() {
    long long n;
    cin >> n;
    
    // T?ng t?t c? c�c s? t? 1 d?n n
    long long total = n * (n + 1) / 2;

    // N?u t?ng kh�ng chia h?t cho 2, kh�ng th? chia d?u
    if (total % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }

    // Chia t?ng th�nh hai ph?n b?ng nhau
    long long target = total / 2;

    // Kh?i t?o m?ng dp
    vector<long long> dp(target + 1, 0);
    dp[0] = 1; // C� 1 c�ch d? t?o t?ng l� 0

    // Duy?t qua c�c s? t? 1 d?n n
    for (int i = 1; i <= n; i++) {
        for (int j = target; j >= i; j--) {
            dp[j] = (dp[j] + dp[j - i]) % MOD;
        }
    }

    // K?t qu? l� s? c�ch chia t?ng / 2, nhung ph?i chia 2 do ho�n d?i gi?a hai t?p con
    cout << dp[target] * 500000004 % MOD << endl; // 500000004 l� 2^(-1) mod 10^9+7
    return 0;
}
