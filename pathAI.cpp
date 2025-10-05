#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000003;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    string s;
    cin >> s;

    int len = s.length();

    // Kh?i t?o m?ng dp v?i k�ch thu?c 2D
    vector<vector<int>> dp_previous(n, vector<int>(n, 0));
    vector<vector<int>> dp_current(n, vector<int>(n, 0));

    // Kh?i t?o tr?ng th�i ban d?u
    if (grid[0][0] == s[0]) {
        dp_previous[0][0] = 1;
    }

    // Duy?t t?ng k� t? c?a chu?i s
    for (int t = 0; t < len - 1; ++t) {
        // X�a m?ng dp_current tru?c khi s? d?ng
        for (int i = 0; i < n; ++i) {
            fill(dp_current[i].begin(), dp_current[i].end(), 0);
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp_previous[i][j] > 0) {
                    // Di chuy?n sang ph?i
                    if (j + 1 < n && grid[i][j + 1] == s[t + 1]) {
                        dp_current[i][j + 1] = (dp_current[i][j + 1] + dp_previous[i][j]) % MOD;
                    }
                    // Di chuy?n xu?ng du?i
                    if (i + 1 < n && grid[i + 1][j] == s[t + 1]) {
                        dp_current[i + 1][j] = (dp_current[i + 1][j] + dp_previous[i][j]) % MOD;
                    }
                }
            }
        }

        // Chuy?n d?i tr?ng th�i
        swap(dp_previous, dp_current);
    }

    // K?t qu? l� s? c�ch di d?n � (n-1, n-1) v?i to�n b? chu?i S d� kh?p
    cout << dp_previous[n-1][n-1] << "\n";

    return 0;
}
