#include <bits/stdc++.h>
#define int long long

using namespace std;

// Hàm tính t?ng kho?ng cách cho m?t danh sách t?a d? 1 chi?u (dã sort)
// val: t?a d? c?a di?m t?p k?t (trên 1 tr?c)
// coords: danh sách t?a d? các di?m giao quà (dã sort)
// prefix: m?ng c?ng d?n c?a coords
int calc_dist(int val, int n, const vector<int>& coords, const vector<int>& prefix) {
    // Tìm v? trí ph?n t? d?u tiên >= val
    // k là s? lu?ng ph?n t? nh? hon val (n?m bên trái)
    int k = lower_bound(coords.begin(), coords.end(), val) - coords.begin();
    
    // Tính t?ng kho?ng cách v?i các di?m bên trái (nh? hon val)
    // Công th?c: k * val - Sum(coords[0]...coords[k-1])
    int left_sum = k * val - prefix[k];
    
    // Tính t?ng kho?ng cách v?i các di?m bên ph?i (l?n hon ho?c b?ng val)
    // Công th?c: Sum(coords[k]...coords[n-1]) - (n-k) * val
    // Sum do?n [k, n-1] = prefix[n] - prefix[k]
    int right_sum = (prefix[n] - prefix[k]) - (n - k) * val;
    
    return left_sum + right_sum;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n;
    if (!(cin >> n)) return 0;
    
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    
    // 1. S?p x?p các m?ng t?a d?
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    
    // 2. Xây d?ng m?ng c?ng d?n (Prefix Sum)
    // px[i] luu t?ng c?a i ph?n t? d?u tiên (t? index 0 d?n i-1)
    vector<int> px(n + 1, 0);
    vector<int> py(n + 1, 0);
    
    for (int i = 0; i < n; i++) {
        px[i+1] = px[i] + x[i];
        py[i+1] = py[i] + y[i];
    }
    
    int q;
    cin >> q;
    while (q--) {
        int qx, qy;
        cin >> qx >> qy;
        
        // Tính toán riêng bi?t cho X và Y
        int distX = calc_dist(qx, n, x, px);
        int distY = calc_dist(qy, n, y, py);
        
        // Ð?ng quên nhân 2 vì ph?i di và v?
        cout << 2 * (distX + distY) << "\n";
    }
    
    return 0;
}
