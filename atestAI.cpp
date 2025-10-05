#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 2023;

signed main() {
    int n, k;
    cin >> n >> k;
    vector<bool> is_broken(n + 1, false);  // ��nh d?u b?c thang b? h?ng
    
    for (int i = 0; i < k; i++) {
        int broken;
        cin >> broken;
        is_broken[broken] = true;
    }
    
    vector<int> dp(n + 1, 0);  // M?ng dp d? luu s? c�ch leo l�n t?ng b?c
    dp[1] = 1;  // C� m?t c�ch d? d?ng ? b?c thang 1
    if (n > 1) dp[2] = is_broken[2] ? 0 : 1;  // C� m?t c�ch d? leo l�n b?c thang 2 (n?u kh�ng b? h?ng)
    
    for (int i = 3; i <= n; i++) {
        if (is_broken[i]) {
            dp[i] = 0;  // N?u b?c thang i b? h?ng th� kh�ng c� c�ch n�o leo l�n
        } else {
            dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;  // T�nh s? c�ch t? b?c i-1 v� i-2
        }
    }

    cout << dp[n] % MOD;  // In ra k?t qu? cu?i c�ng
}


