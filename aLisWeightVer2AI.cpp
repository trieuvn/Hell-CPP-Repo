#include<bits/stdc++.h>
#define int long long
 
using namespace std;

int a[1000000];  
int w[1000000];  
vector<int> vec; 

int bin(int left, int right, int x) {
    int mid = (left + right) / 2;
    while (left <= right) {
        if (a[vec[mid]] == x) {
            return mid;
        } else if (x > a[vec[mid]]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
        mid = (left + right) / 2;
    }
    return left;
}
 
signed main() {
    int n, i;
    cin >> n;
    
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (i = 0; i < n; i++) {
        cin >> w[i];
    }

    vector<int> lis;             
    vector<int> dp(n+1);         
    vector<int> trace(n+1, -1);    
    int t, maxIndex = 0;         

    dp[0] = w[0];
    vec.push_back(0);

    for (i = 1; i < n; i++) {
        if (a[i] > a[vec.back()]) {
            trace[i] = vec.back();
            dp[i] = dp[vec.back()] + w[i];
            vec.push_back(i);
        } else {
            t = bin(0, vec.size() - 1, a[i]);
            if (t > 0) {
                if (dp[i] < dp[vec[t - 1]] + w[i]) {
                    dp[i] = dp[vec[t - 1]] + w[i];
                    trace[i] = vec[t - 1];
                }
            } else {
                dp[i] = w[i];
            }
            vec[t] = i;  
        }

        if (dp[i] > dp[maxIndex]) {
            maxIndex = i;
        }
    }

    for (i = maxIndex; i != -1; i = trace[i]) {
        lis.push_back(i + 1);
    }
    
    cout << lis.size() << "\n";
    reverse(lis.begin(), lis.end());
    for (long k : lis) {
        cout << k << " ";
    }
}

