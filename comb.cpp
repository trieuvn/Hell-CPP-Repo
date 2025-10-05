#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;

// Hàm tính luy th?a nhanh (Modular Exponentiation)
int mod_exp(int a, int b, int mod) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

// Hàm tính t? h?p C(n, k) theo modulo
int comb(int n, int k) {
    if (k > n || k < 0) return 0;
    int res = 1;
    for (int i = 1; i <= k; i++) {
        res = res * (n - i + 1) % MOD * mod_exp(i, MOD - 2, MOD) % MOD;
    }
    return res;
}

// Phân tích s? n thành th?a s? nguyên t? và d?m s? mu
vector<pair<int,int> > prime_factorize(int n) {
    vector<pair<int, int> > factors;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int count = 0;
            while (n % i == 0) {
                n /= i;
                count++;
            }
            factors.push_back({i, count});
        }
    }
    if (n > 1) factors.push_back({n, 1});
    return factors;
}

// Ð?m s? dãy t?t
int count_good_sequences(int n, int k) {
    vector<pair<int, int> > factors = prime_factorize(n); // L?y th?a s? nguyên t? và s? mu
    int result = 1;

    // V?i m?i th?a s? nguyên t? p có s? mu m, áp d?ng t? h?p C(m + k - 1, k - 1)
    for (pair<int,int> a : factors) {
        result = result * comb(a.second + k - 1, k - 1) % MOD;
    }

    return result;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    cout << count_good_sequences(n, k) << "\n";
    return 0;
}

