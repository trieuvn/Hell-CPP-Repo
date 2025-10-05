#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

const int INF = INT_MAX; // Gi� tr? v� c�ng

int n, m, start, end;
vector<int> h; // Nhi?t d? c?a c�c d?a di?m
vector<vector<pair<int, int>>> adj; // Danh s�ch k?

void dijkstra() {
    // T?o m?ng dist luu gi� tr? ch�nh l?ch l?n nh?t nh? nh?t
    vector<int> dist(n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    // Kh?i t?o di?m b?t d?u
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        // N?u d� duy?t d?n noi v� kh�ng c?n c?p nh?t
        if (d > dist[u]) continue;
        
        // Duy?t c�c d?nh k? c?a u
        for (auto edge : adj[u]) {
            int v = edge.first;
            int cost = abs(h[u] - h[v]); // Ch�nh l?ch nhi?t d? gi?a u v� v
            
            // N?u ch�nh l?ch l?n nh?t nh? hon gi� tr? hi?n t?i c?a dist[v]
            if (dist[v] > max(dist[u], cost)) {
                dist[v] = max(dist[u], cost);
                pq.push({dist[v], v});
            }
        }
    }
    
    if (dist[end] == INF) {
        cout << -1 << '\n'; // Kh�ng c� du?ng di
    } else {
        cout << dist[end] << '\n'; // �? ch�nh l?ch nhi?t d? l?n nh?t nh? nh?t
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    // Nh?p d? li?u
    cin >> n >> m >> start >> end;
    start--; end--; // ��nh s? t? 0
    
    h.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    
    adj.resize(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--; // ��nh s? t? 0
        adj[u].push_back({v, abs(h[u] - h[v])});
        adj[v].push_back({u, abs(h[u] - h[v])});
    }
    
    // Ch?y thu?t to�n Dijkstra d? t�m d? ch�nh l?ch nh? nh?t
    dijkstra();
    
    return 0;
}
