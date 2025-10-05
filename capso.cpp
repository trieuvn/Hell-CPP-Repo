#include <iostream>
#include <algorithm> // Thu vi?n cho hàm sort
using namespace std;

int main() {
    int n, x;
    
    // Ð?c d? li?u t? console
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> x;
    
    // S?p x?p m?ng
    sort(a, a + n);

    int left = 0;
    int right = n - 1;
    int count = 0;

    // S? d?ng hai con tr?
    while (left < right) {
        int sum = a[left] + a[right];
        if (sum == x) {
            count++;
            left++;
            right--;
        } else if (sum < x) {
            left++;
        } else {
            right--;
        }
    }

    // Xu?t k?t qu? ra console
    cout << count << endl;

    return 0;
}
