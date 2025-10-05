#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int64 MOD = 1000000007;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    if(!(cin >> s)) return 0;
    int m = s.size();

    // f[val] = s? c?p (x,y) v?i 0<=x,y<=9 và x+y = val
    vector<int64> f(19, 0);
    for (int val = 0; val <= 18; ++val) {
        if (val <= 9) f[val] = val + 1;
        else f[val] = 19 - val;
    }

    vector<int64> dp(m+1, 0);
    dp[m] = 1; // suffix r?ng có 1 cách

    for (int i = m-1; i >= 0; --i) {
        // len = 1
        {
            int val = s[i] - '0';
            if (0 <= val && val <= 18) {
                dp[i] = (dp[i] + f[val] * dp[i+1]) % MOD;
            }
        }
        // len = 2 (không cho do?n có leading zero)
        if (i+1 < m && s[i] != '0') {
            int val = (s[i]-'0')*10 + (s[i+1]-'0');
            if (0 <= val && val <= 18) {
                dp[i] = (dp[i] + f[val] * dp[i+2]) % MOD;
            }
        }
    }

    cout << dp[0] % MOD << "\n";
    return 0;
}

