#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1e6+5;
const int MOD = 1e9+7;

int n, m;
int a[MAX];  
int color[MAX];  
long long ans = 0; 

bool isValid() {
    for (int i = 1; i <= n; i++) {
        if (a[i] != i) {
            if (color[i] == color[a[i]]) return false;
        }
    }
    return true;
}

void dfs(int u) {
    if (u > n) {
        if (isValid()) {
            ans = (ans + 1)%MOD;
        }
        return;
    }

    for (int c = 1; c <= m; c++) {
        color[u] = c; 
        dfs(u + 1);   
    }
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for (int i = 1; i <= n; i++) {
        cin>>a[i];
    }

    dfs(1);

    cout << ans%MOD;
}
