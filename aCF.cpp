#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;  // �?c s? lu?ng test cases

    while (t--) {
        int n;
        cin >> n;  // S? lu?ng cu?c thi

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];  // C�c di?m s? d�nh gi� c?a c�c cu?c thi
        }

        // Bu?c 1: T�nh di?m s? ban d?u n?u kh�ng b? qua b?t k? cu?c thi n�o.
        int score = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > score) {
                score++;
            } else if (a[i] == score) {
                // kh�ng thay d?i di?m
            } else {
                score--;
            }
        }

        // Bu?c 2: T�m do?n t?i uu d? b? qua
        // Ch�ng ta duy?t qua t?ng do?n d? t�m di?m s? t?i uu.
        int max_score = score;  // �i?m t?i da ban d?u
        for (int l = 0; l < n; l++) {
            int current_score = score;
            for (int r = l; r < n; r++) {
                if (a[r] > current_score) {
                    current_score++;
                } else if (a[r] == current_score) {
                    // kh�ng thay d?i di?m
                } else {
                    current_score--;
                }
                // C?p nh?t di?m t?i da
                max_score = max(max_score, current_score);
            }
        }

        cout << max_score << endl;
    }

    return 0;
}

