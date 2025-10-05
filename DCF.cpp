#include <iostream>
#include <vector>

using namespace std;

// Function to query if the path between nodes `a` and `b` passes through root (0)
bool query(int a, int b) {
    cout << "? " << a << " " << b << endl;
    cout.flush();
    int result;
    cin >> result;
    return result == 1; // returns true if path passes through root
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        // Handle small cases directly
        if (n == 1) {
            cout << "! 0" << endl;
            continue;
        } else if (n == 2) {
            cout << "! 0 0" << endl;
            continue;
        }

        vector<int> parents(n, -1); // Store the parent of each node
        
        // Example usage of query to check between pairs of nodes
        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                bool res = query(i, j);
                if (res) {
                    // If path passes through root, `i` and `j` are in different subtrees
                    // Example logic to set parents (you'll customize as per structure)
                    parents[j] = i; // Example placeholder logic
                } else {
                    // If they belong to the same subtree
                    // Implement additional logic if needed
                }
            }
        }

        // Output the parent array for this test case
        cout << "! ";
        for (int i = 1; i < n; ++i) {
            cout << parents[i] << " ";
        }
        cout << endl;
        cout.flush();
    }
}

int main() {
    solve();
    return 0;
}

