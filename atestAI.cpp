#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 2023;

signed main() {
    int n, k;
    cin >> n >> k;
    vector<bool> is_broken(n + 1, false);  // Ðánh d?u b?c thang b? h?ng
    
    for (int i = 0; i < k; i++) {
        int broken;
        cin >> broken;
        is_broken[broken] = true;
    }
    
    vector<int> dp(n + 1, 0);  // M?ng dp d? luu s? cách leo lên t?ng b?c
    dp[1] = 1;  // Có m?t cách d? d?ng ? b?c thang 1
    if (n > 1) dp[2] = is_broken[2] ? 0 : 1;  // Có m?t cách d? leo lên b?c thang 2 (n?u không b? h?ng)
    
    for (int i = 3; i <= n; i++) {
        if (is_broken[i]) {
            dp[i] = 0;  // N?u b?c thang i b? h?ng thì không có cách nào leo lên
        } else {
            dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;  // Tính s? cách t? b?c i-1 và i-2
        }
    }

    cout << dp[n] % MOD;  // In ra k?t qu? cu?i cùng
}


