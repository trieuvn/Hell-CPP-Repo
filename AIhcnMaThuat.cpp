#include<bits/stdc++.h>
using namespace std;

// H�m ki?m tra xem m?t s? c� ph?i s? ch�nh phuong kh�ng
bool isSquare(int x) {
    int sq = sqrt(x);
    return sq * sq == x;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));

    // Nh?p ma tr?n
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int result = 0;

    // Ch?n hai d�ng kh�c nhau
    for (int r1 = 0; r1 < n; r1++) {
        for (int r2 = r1 + 1; r2 < n; r2++) {

            // Ch?n hai c?t kh�c nhau
            for (int c1 = 0; c1 < m; c1++) {
                for (int c2 = c1 + 1; c2 < m; c2++) {
                    
                    // L?y b?n � l� d?nh c?a h�nh ch? nh?t
                    int num1 = grid[r1][c1];
                    int num2 = grid[r1][c2];
                    int num3 = grid[r2][c1];
                    int num4 = grid[r2][c2];

                    // Ki?m tra c� bao nhi�u s? l� s? ch�nh phuong
                    int count = isSquare(num1) + isSquare(num2) + isSquare(num3) + isSquare(num4);

                    // N?u c� �t nh?t 3 s? ch�nh phuong, th� d�y l� m?t h�nh ch? nh?t h?p l?
                    if (count >= 3) {
                        result++;
                    }
                }
            }
        }
    }

    // In ra k?t qu?
    cout << result << endl;
}

