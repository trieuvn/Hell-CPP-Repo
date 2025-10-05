#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;

    // Chuy?n x v� y th�nh chu?i k� t?
    string x_str = to_string(x);
    string y_str = to_string(y);

    // S?p x?p c�c chu?i k� t? d? t?o s? b� nh?t v� l?n nh?t
    sort(x_str.begin(), x_str.end());
    sort(y_str.begin(), y_str.end());

    // T?o s? b� nh?t v� l?n nh?t b?ng c�ch n?i c�c chu?i
    string min_z = x_str + y_str;
    string max_z = y_str + x_str;

    // Chuy?n k?t qu? v? d?ng s? nguy�n
    int min_z_int = stoi(min_z);
    int max_z_int = stoi(max_z);

    // In ra k?t qu?
    cout << min_z_int << endl;
    cout << max_z_int << endl;

    return 0;
}
