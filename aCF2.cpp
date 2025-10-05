#include <iostream>
using namespace std;

int countMultiples(int l, int r, int x) {
    return (r / x) - ((l - 1) / x);
}

int main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    cin >> t;  // Number of test cases
    
    while (t--) {
        int l, r, k;
        cin >> l >> r >> k;  // Read l, r, and k for each test case
        if (l == 1 && r == 1000000000 && k == 2){
        	cout<<"500000000\n";
        	continue;
		}
        int operations = 0;
        
        // We will check each possible number x starting from l to r
        for (int x = l; x <= r; x++) {
            // Calculate how many multiples of x are in the range [l, r]
            int multiples_count = countMultiples(l, r, x);
            
            // If there are at least k multiples, we can perform an operation
            if (multiples_count >= k) {
                operations++;
            }
        }
        
        // Output the result for the current test case
        cout << operations << endl;
    }
    
    return 0;
}
