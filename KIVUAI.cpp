#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long n, m;
    cin >> n >> m;
    vector<long> heightsN(n);
    vector<long> heightsM(m);

    for (long i = 0; i < n; i++) {
        cin >> heightsN[i];
    }

    for (long i = 0; i < m; i++) {
        cin >> heightsM[i];
    }

    // S?p x?p danh s�ch chi?u cao c?a c? hai nh�m
    sort(heightsN.begin(), heightsN.end());
    sort(heightsM.begin(), heightsM.end());

    long count = 0; // S? lu?ng d�i khi�u vu nhi?u nh?t

    long i = n - 1, j = m - 1;
    while (i >= 0 && j >= 0) {
        if (heightsN[i] > heightsM[j]) {
            // T�m du?c m?t c?p d�i khi�u vu
            count++;
            i--;
            j--;
        } else {
            // B?n nam kh�ng cao hon b?n n?, ti?p t?c t�m trong danh s�ch kh�c
            j--;
        }
    }

    cout << count << endl;

    return 0;
}
