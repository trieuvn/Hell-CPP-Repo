#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;  // S? lu?ng test cases
    
    while (t--) {
        int n;
        cin >> n;
        
        string s, r;
        cin >> s >> r;
        
        int diff_count = 0;  // Ð?m s? c?p khác nhau trong s
        
        // Duy?t chu?i s d? d?m s? c?p khác nhau
        for (int i = 0; i < n - 1; i++) {
            if (s[i] != s[i + 1]) {
                diff_count++;
            }
        }
        
        // N?u s? c?p khác nhau d? l?n thì in YES, ngu?c l?i NO
        if (diff_count >= n - 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}

