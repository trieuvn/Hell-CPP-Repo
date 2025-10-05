#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long X;
    cin >> X;

    // Bu?c 1: T?o dãy s? Fibonacci nh? hon ho?c b?ng X
    vector<long long> fibo = {1, 1};
    while (true) {
        long long nextFibo = fibo.back() + fibo[fibo.size() - 2];
        if (nextFibo > X) break;
        fibo.push_back(nextFibo);
    }

    // Bu?c 2: S? d?ng phuong pháp tham lam d? phân tích X
    int count = 0;
    for (int i = fibo.size() - 1; i >= 0 && X > 0; i--) {
        if (fibo[i] <= X) {
            X -= fibo[i];
            count++;
        }
    }

    // In ra k?t qu?
    cout << count << endl;

    return 0;
}
