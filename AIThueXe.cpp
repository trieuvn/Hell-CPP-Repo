#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long n;
    cin >> n;
    vector<pair<long, long>> cars(n);  // cars[i] = {p[i], t[i]} - giá và ngày cu?i cùng có th? thuê
    for (long i = 0; i < n; ++i) {
        long t, p;
        cin >> t >> p;
        cars[i] = {p, t};  // luu {giá, ngày cu?i cùng có th? thuê}
    }

    // Priority queue luu các xe theo giá tang d?n (min-heap).
    priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long, long>>> pq;

    long sum = 0;
    long current_day = 1;
    long i = 0; // Bi?n d? duy?t qua danh sách các xe.

    while (current_day <= n) {
        // Thêm t?t c? các xe có s?n vào ngày hi?n t?i.
        while (i < n && cars[i].second >= current_day) {
            pq.push(cars[i]);  // Thêm xe vào heap
            i++;
        }

        // Lo?i b? các xe không th? thuê trong ngày hi?n t?i n?a.
        while (!pq.empty() && pq.top().second < current_day) {
            pq.pop();
        }

        // N?u hàng d?i r?ng, t?c là không có xe nào d? thuê cho ngày này.
        if (pq.empty()) {
            cout << -1;  // Không th? thuê xe cho m?i ngày
            return 0;
        }

        // Ch?n xe có giá r? nh?t t? priority queue.
        sum += pq.top().first;
        pq.pop();

        current_day++;  // Chuy?n sang ngày ti?p theo.
    }

    cout << sum;
    return 0;
}
