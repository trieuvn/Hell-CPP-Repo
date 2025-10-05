#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
const int MAXQ = 1e5 + 5;

int A[MAXN]; // M?ng A
int freq[MAXN]; // M?ng luu t?n su?t c?a các ph?n t? trong ph?m vi hi?n t?i
int result[MAXQ]; // M?ng luu k?t qu? cho các truy v?n

struct Query {
    int l, r, x, idx;
};

int n, q;

// Hàm so sánh cho vi?c s?p x?p các truy v?n
bool cmp(Query &a, Query &b) {
    int blockSize = sqrt(n);
    if (a.l / blockSize != b.l / blockSize) return a.l / blockSize < b.l / blockSize;
    return a.r < b.r;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    
    // Ð?c m?ng A
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    // Ð?c các truy v?n
    vector<Query> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].l >> queries[i].r >> queries[i].x;
        queries[i].idx = i;
    }

    // S?p x?p các truy v?n theo thu?t toán Mo
    sort(queries.begin(), queries.end(), cmp);

    // Bi?n dùng d? luu k?t qu? t?m th?i
    int l = 1, r = 0;
    int answer = 0;
    map<int, int> countExact; // Map d? luu s? lu?ng ph?n t? xu?t hi?n chính xác x l?n trong ph?m vi

    // Hàm thêm ph?n t? vào ph?m vi
    auto add = [&](int i) {
        int val = A[i];
        int count = ++freq[val];
        
        if (count == queries[0].x) {
            countExact[count]++;
        } else if (count == queries[0].x + 1) {
            countExact[count]--;
        }
    };

    // Hàm xóa ph?n t? kh?i ph?m vi
    auto remove = [&](int i) {
        int val = A[i];
        int count = --freq[val];
        
        if (count == queries[0].x) {
            countExact[count]++;
        } else if (count == queries[0].x + 1) {
            countExact[count]--;
        }
    };

    // X? lý t?ng truy v?n
    for (auto &q : queries) {
        while (r < q.r) {
            r++;
            add(r);
        }
        while (r > q.r) {
            remove(r);
            r--;
        }
        while (l < q.l) {
            remove(l);
            l++;
        }
        while (l > q.l) {
            l--;
            add(l);
        }

        // Luu k?t qu? cho truy v?n
        result[q.idx] = countExact[queries[0].x];
    }

    // In k?t qu? cho t?ng truy v?n
    for (int i = 0; i < q; i++) {
        cout << result[i] << "\n";
    }

    return 0;
}

