#include <iostream>
#include <string>

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;

    string x_str = to_string(x);
    string y_str = to_string(y);

    string min_z = x_str + y_str;
    string max_z = y_str + x_str;

    cout << min_z << endl;
    cout << max_z << endl;

    return 0;
}
