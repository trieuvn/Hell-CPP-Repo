#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    unsigned int n;
    cin >> n;
    
    long long a[n+1], prefix = 0, Max = -1e18, Min = 0;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        prefix += a[i];    // T�nh t?ng ti?n t? d?n a[i]
        Max = max(Max, prefix - Min);  // T�m kho?ng ch�nh l?ch l?n nh?t gi?a t?ng hi?n t?i v� gi� tr? nh? nh?t tru?c d�
        Min = min(Min, prefix);   // C?p nh?t gi� tr? nh? nh?t c?a t?ng ti?n t?
    }

    cout << Max;

    return 0;
}
