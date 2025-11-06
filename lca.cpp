#include<bits/stdc++.h>
#define int long long

using namespace std;
const int sl = 1e5 + 5; 
const int LOGN = 20; 

int n, m; 

vector<vector<int>> adj(sl); 
int h[sl];                   
int up[sl][LOGN];           

void dfs(int u, int p) {
    h[u] = h[p] + 1;
    up[u][0] = p;

    for (int v : adj[u]) {
        if (v != p) { 
            dfs(v, u);
        }
    }
}

void preprocess() {
    h[0] = 0;
    up[1][0] = 0; 
    dfs(1, 0); 

    for (int i = 1; i < LOGN; i++) {
        for (int u = 1; u <= n; u++) {
            if (up[u][i - 1] != 0) {
                up[u][i] = up[up[u][i - 1]][i - 1];
            } else {
                up[u][i] = 0; 
            }
        }
    }
}

int lca(int u, int v) {
    if (h[u] < h[v]) {
        swap(u, v);
    }

    int k = h[u] - h[v];
    for (int i = LOGN - 1; i >= 0; i--) {
        if ((k >> i) & 1) { 
            u = up[u][i];
        }
    }

    if (u == v) {
        return u;
    }

    for (int i = LOGN - 1; i >= 0; i--) {
        if (up[u][i] != 0 && up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }

    return up[u][0];
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    cin >> n >>m;
    
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    preprocess();

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        cout <<lca(u, v) << " ";
    }

    return 0;
}