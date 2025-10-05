#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> A(n), B(n);
    for (auto &x : A) cin >> x;
    for (auto &x : B) cin >> x;
    vector<vector<long long>> dp(n, vector<long long>(n));
    long long ans = LLONG_MIN;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            long long prod = A[i] * B[j];
            long long val;
            if (i == 0 || j == 0) {
                val = prod;
            } else {
                long long prev = dp[i - 1][j - 1];
                val = prod + (prev > 0 ? prev : 0LL);
            }
            dp[i][j] = val;
            ans = max(ans, val);
        }
    }
    cout << ans << '\n';
}
