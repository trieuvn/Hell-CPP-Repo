#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

struct Edge {
    int node;
    int weight;
};

int prim(int start, int target, int n, vector<vector<Edge>>& graph) {
    vector<int> minEdge(n + 1, INT_MAX);
    vector<bool> inMST(n + 1, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    minEdge[start] = 0;
    pq.push({0, start});
    
    int maxEdgeInPath = INT_MIN;
    
    while (!pq.empty()) {
        int u = pq.top().second;
        int currentWeight = pq.top().first;
        pq.pop();
        
        if (inMST[u]) continue; // Skip if already in MST
        inMST[u] = true;
        
        maxEdgeInPath = max(maxEdgeInPath, currentWeight);
        if (u == target) return maxEdgeInPath; // Early exit if target reached
        
        for (Edge& edge : graph[u]) {
            int v = edge.node;
            int weight = edge.weight;
            
            if (!inMST[v] && weight < minEdge[v]) {
                minEdge[v] = weight;
                pq.push({weight, v});
            }
        }
    }
    return -1; // Return -1 if target is unreachable (should not happen in this problem)
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int m, n, s, t;
    cin >> m >> n >> s >> t;
    
    vector<int> heights(m + 1);
    for (int i = 1; i <= m; ++i) {
        cin >> heights[i];
    }
    
    vector<vector<Edge>> graph(m + 1);
    for (int i = 0; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        int weight = abs(heights[u] - heights[v]);
        
        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight});
    }
    
    cout << prim(s, t, m, graph);
    return 0;
}
