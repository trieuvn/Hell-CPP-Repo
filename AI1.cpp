#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    unsigned long n;
    cin >> n;
    
    // M?ng d? luu các d?nh c?a các dãy con không tang d?n
    unsigned long long tops[n];
    unsigned long numTops = 0; // S? lu?ng các dãy con (s? màu c?n dùng)
    
    unsigned long long a;
    cin >> a;
    tops[numTops++] = a; // Kh?i t?o dãy con d?u tiên
    
    for (unsigned long i = 1; i < n; ++i) {
        cin >> a;
        
        // Tìm v? trí thích h?p trong tops d? thay th?
        bool placed = false;
        for (unsigned long j = 0; j < numTops; ++j) {
            if (tops[j] >= a) {
                tops[j] = a;
                placed = true;
                break;
            }
        }
    
        // N?u không tìm th?y v? trí thích h?p, thêm dãy con m?i
        if (!placed) {
            tops[numTops++] = a;
        }
    }
    
    cout << numTops << endl;
    
    return 0;
}
