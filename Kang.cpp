#include<bits/stdc++.h>
using namespace std;

int fnum(string n) {
    while (n.size() > 1) {
        int sum = 0;
        for (char digit : n) {
            sum += digit -'0';
        }
        n = to_string(sum);
    }
    return n[0] -'0';
}

int main() {
    string a,b;
    cin >> a;
    cin>>b;
    int tong;
    tong = (a-'0')+(b-'0');

    
    cout << tong << endl;

    return 0;
}
