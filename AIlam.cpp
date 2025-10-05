#include <iostream>

using namespace std;

int main() {
    long long m, n, k;
    cin >> m >> n >> k;

    long long A[m], B[n];
    
    for (long long i = 0; i < m; ++i) {
        cin >> A[i];
    }
    
    for (long long j = 0; j < n; ++j) {
        cin >> B[j];
    }

    long long count = 0;

    for (long long i = 0; i < m; ++i) {
        if (A[i] == 0) {
            if (k == 0) {
                count += n; // N?u k=0 và A[i]=0 thì nhân v?i b?t k? B[j] nào cung cho k?t qu? b?ng 0
            }
            continue; // Tránh chia cho 0
        }
        if (k % A[i] == 0) {
            long long target = k / A[i];
            for (long long j = 0; j < n; ++j) {
                if (B[j] == target) {
                    count++;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}
