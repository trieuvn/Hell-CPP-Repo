#include<bits/stdc++.h>

using namespace std;
long a[10000];
vector<long> t(40000, 1);  // Segment tree l?n g?p 4 l?n s? ph?n t?
vector<long> trace(10000, -1);  // Dùng d? luu ch? s? ph?n t? tru?c dó trong dãy con

void update(long v, long l, long r, long pos, long val, long prev_idx){
    if (l == r) {
        t[v] = val;
        trace[pos] = prev_idx;  // Luu ch? s? ph?n t? tru?c dó
    } else {
        long m = (l + r) / 2;
        if (pos <= m) {
            update(2 * v, l, m, pos, val, prev_idx);
        } else {
            update(2 * v + 1, m + 1, r, pos, val, prev_idx);
        }
        t[v] = max(t[2 * v], t[2 * v + 1]);
    }
}

long query(long v, long tl, long tr, long l, long r) {
    if (l > r) return 0;
    if (tl == l && tr == r) {
        return t[v];
    } else {
        long tm = (tl + tr) / 2;
        long s1 = query(2 * v, tl, tm, l, min(r, tm));
        long s2 = query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
        return max(s1, s2);
    }
}

int main() {
    long n, i, MaxNum = LONG_MIN;
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
        MaxNum = max(MaxNum, a[i]);
    }

    vector<long> lis(n + 1, 0);  // Luu d? dài LIS t?i m?i v? trí
    vector<long> previous_index(n + 1, -1);  // Luu ch? s? tru?c dó c?a dãy con

    for (i = 1; i <= n; i++) {
        long d = query(1, 0, MaxNum, 1, a[i] - 1) + 1;  // Tìm d? dài LIS t?i a[i]
        
        // Tìm v? trí ch? s? c?a ph?n t? tru?c dó
        long prev_idx = -1;
        for (long j = 1; j <= a[i] - 1; j++) {
            if (query(1, 0, MaxNum, j, j) == d - 1) {
                prev_idx = j;  // Luu l?i ch? s? ph?n t? tru?c dó
                break;
            }
        }
        
        update(1, 0, MaxNum, a[i], d, prev_idx);  // C?p nh?t segment tree và trace
    }

    // Tìm v? trí có d? dài LIS l?n nh?t
    long max_len = 0, last_idx = -1;
    for (i = 1; i <= n; i++) {
        long current_lis = query(1, 0, MaxNum, a[i], a[i]);
        if (current_lis > max_len) {
            max_len = current_lis;
            last_idx = a[i];
        }
    }

    // Truy ngu?c l?i dãy con tang dài nh?t
    vector<long> lis_sequence;
    while (last_idx != -1) {
        lis_sequence.push_back(last_idx);
        last_idx = trace[last_idx];  // Truy ngu?c ch? s? ph?n t? tru?c dó
    }

    // In ra dãy con tang dài nh?t theo th? t? t? d?u d?n cu?i
    reverse(lis_sequence.begin(), lis_sequence.end());
    for (long x : lis_sequence) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
