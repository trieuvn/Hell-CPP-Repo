#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    unsigned long n;
    cin >> n;
    
    // M?ng d? luu c�c d?nh c?a c�c d�y con kh�ng tang d?n
    unsigned long long tops[n];
    unsigned long numTops = 0; // S? lu?ng c�c d�y con (s? m�u c?n d�ng)
    
    unsigned long long a;
    cin >> a;
    tops[numTops++] = a; // Kh?i t?o d�y con d?u ti�n
    
    for (unsigned long i = 1; i < n; ++i) {
        cin >> a;
        
        // T�m v? tr� th�ch h?p trong tops d? thay th?
        bool placed = false;
        for (unsigned long j = 0; j < numTops; ++j) {
            if (tops[j] >= a) {
                tops[j] = a;
                placed = true;
                break;
            }
        }
    
        // N?u kh�ng t�m th?y v? tr� th�ch h?p, th�m d�y con m?i
        if (!placed) {
            tops[numTops++] = a;
        }
    }
    
    cout << numTops << endl;
    
    return 0;
}
