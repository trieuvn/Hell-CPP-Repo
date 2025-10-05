#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int sum_a = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum_a += a[i];
        }

        // Check if balancing is possible
        if (sum_a % n != 0) {
            cout << -1 << endl;
            continue;
        }

        int target = sum_a / n;
        vector<int> operations(n, 0);

        // Calculate the operations to balance each element to `target`
        int balance = 0;
        for (int i = 0; i < n; i++) {
            balance += a[i] - target;
            operations[i] = abs(balance);
        }

        // Output the operations
        for (int i = 0; i < n; i++) {
            cout << operations[i] << " ";
        }
        cout << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}


