#include <iostream>
#include <cstring>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    string b, a;
    cin >> b >> a;

    long long count = 0;
    long long lenB = b.length();
    long long lenA = a.length();

    for (long long i = 0; i <= lenA - lenB; i++) {
        // Ki?m tra xem chu?i con b?t d?u t?i v? trí i có b?ng v?i chu?i B không
        if (a.substr(i, lenB) == b) {
            count++;
        }
    }

    cout << count << "\n";
}
