#include <iostream>
#include <string>
using namespace std;

int findLongestUniqueSubstring(const string& s) {
    int n = s.length();
    int maxLength = 0;
    int left = 0;
    int right = 0;
    int count[26] = {0};

    while (right < n) {
        char currentChar = s[right] - 'a';
        count[currentChar]++;
        while (count[currentChar] > 1) {
            char leftChar = s[left] - 'a';
            count[leftChar]--;
            left++;
        }
        maxLength = max(maxLength, right - left + 1);
        right++;
    }

    return maxLength;
}

int main() {
    string s;
    getline(cin, s);

    int maxLength = findLongestUniqueSubstring(s);
    cout<< maxLength << endl;

    return 0;
}
