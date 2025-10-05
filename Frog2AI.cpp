#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int h[n];
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    int dp[n];
    dp[0] = 0;

    for (int i = 1; i < n; i++) {
        dp[i] = INT_MAX;

        for (int j = 1; j <= k && i - j >= 0; j++) {
            dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
        }
    }

    cout << dp[n - 1] << endl;

    return 0;
}
