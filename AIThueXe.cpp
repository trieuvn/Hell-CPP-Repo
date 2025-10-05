#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long n;
    cin >> n;
    vector<pair<long, long>> cars(n);  // cars[i] = {p[i], t[i]} - gi� v� ng�y cu?i c�ng c� th? thu�
    for (long i = 0; i < n; ++i) {
        long t, p;
        cin >> t >> p;
        cars[i] = {p, t};  // luu {gi�, ng�y cu?i c�ng c� th? thu�}
    }

    // Priority queue luu c�c xe theo gi� tang d?n (min-heap).
    priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long, long>>> pq;

    long sum = 0;
    long current_day = 1;
    long i = 0; // Bi?n d? duy?t qua danh s�ch c�c xe.

    while (current_day <= n) {
        // Th�m t?t c? c�c xe c� s?n v�o ng�y hi?n t?i.
        while (i < n && cars[i].second >= current_day) {
            pq.push(cars[i]);  // Th�m xe v�o heap
            i++;
        }

        // Lo?i b? c�c xe kh�ng th? thu� trong ng�y hi?n t?i n?a.
        while (!pq.empty() && pq.top().second < current_day) {
            pq.pop();
        }

        // N?u h�ng d?i r?ng, t?c l� kh�ng c� xe n�o d? thu� cho ng�y n�y.
        if (pq.empty()) {
            cout << -1;  // Kh�ng th? thu� xe cho m?i ng�y
            return 0;
        }

        // Ch?n xe c� gi� r? nh?t t? priority queue.
        sum += pq.top().first;
        pq.pop();

        current_day++;  // Chuy?n sang ng�y ti?p theo.
    }

    cout << sum;
    return 0;
}
