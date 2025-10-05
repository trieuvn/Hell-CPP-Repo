#include <bits/stdc++.h>
#define int long long

using namespace std;

const int sl = 1e5+5;
vector<int> p[sl];
vector<bool> vis(sl, false);
vector<int> path(sl, -1);

void bfs(int start) {
    queue<int> q;
    q.push(start);
    path[start] = 0;
    vis[start] = true;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        for (int neighbor : p[node]) {
            if (!vis[neighbor]) {
                vis[neighbor] = true;
                path[neighbor] = path[node] + 1;
                q.push(neighbor);
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        p[u].push_back(v);
        p[v].push_back(u);
    }
    
    bfs(1);
    
    for (int i = 2; i <= n; i++) {
        cout << path[i] << " ";
    }
}
