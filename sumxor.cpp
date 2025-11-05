#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

using int128 = __int128_t;

// Ðây là hàm in, v? co b?n là logic c?a b?n
// d?t trong m?t hàm bình thu?ng
void print128(int128 n) {
    if (n < 0) {
        std::cout << "-";
        n = -n;
    }
    if (n == 0) {
        std::cout << "0";
        return;
    }
    std::string s;
    while (n) {
        s += (char)(n % 10 + '0');
        n /= 10;
    }
    std::reverse(s.begin(), s.end());
    std::cout << s;
}

int main() {
    long long a;
    long long b;
    long long c;
    
    cin>>a>>b>>c;
    
    int128 result = ((int128)a * (int128)b) % c;

    // B?n ph?i g?i hàm này thay vì dùng cout tr?c ti?p
    print128(result);
    std::cout << "\n";

    return 0;
}
