#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

int n, p, q;
string S;
int power10[10]; // Luu giá tr? 10^d % p
int freq[10];    // T?n su?t xu?t hi?n các ch? s?
int currentRes = 0; // K?t qu? cho do?n hi?n t?i

struct Query {
    int l, r, idx;
};

vector<Query> queries;
int res[MAXN];

// Tính tru?c 10^d % p
void precomputePower10() {
    power10[0] = 1 % p;
    for (int i = 1; i < 10; ++i) {
        power10[i] = (power10[i - 1] * 10) % p;
    }
}

// Hàm so sánh truy v?n theo thu?t toán Mo
bool compare(const Query &a, const Query &b) {
    int block_a = a.l / sqrt(n);
    int block_b = b.l / sqrt(n);
    if (block_a != block_b)
        return block_a < block_b;
    return (block_a & 1) ? (a.r < b.r) : (a.r > b.r);
}

// Thêm ký t? vào do?n
void add(int pos) {
    int digit = S[pos] - '0';
    for (int d = 0; d < 10; ++d) {
        currentRes += freq[d] * ((digit * power10[1] + d) % p == 0);
    }
    freq[digit]++;
}

// Lo?i b? ký t? kh?i do?n
void remove(int pos) {
    int digit = S[pos] - '0';
    freq[digit]--;
    for (int d = 0; d < 10; ++d) {
        currentRes -= freq[d] * ((digit * power10[1] + d) % p == 0);
    }
}

// X? lý t?ng truy v?n
void solve() {
    int currentL = 0, currentR = 0;
    for (auto query : queries) {
        int l = query.l - 1, r = query.r - 1;

        // Di chuy?n currentL, currentR t?i [l, r]
        while (currentL > l) add(--currentL);
        while (currentR < r) add(currentR++);
        while (currentL < l) remove(currentL++);
        while (currentR > r) remove(--currentR);

        // Luu k?t qu? cho truy v?n
        res[query.idx] = currentRes;
    }
}

int main() {
    cin >> p;
    cin >> S;
    n = S.size();
    cin >> q;

    // Ð?c truy v?n
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        queries.push_back({l, r, i});
    }

    // Ti?n x? lý
    precomputePower10();
    sort(queries.begin(), queries.end(), compare);

    // Gi?i quy?t truy v?n
    solve();

    // Xu?t k?t qu?
    for (int i = 0; i < q; ++i) {
        cout << res[i] << "\n";
    }

    return 0;
}

