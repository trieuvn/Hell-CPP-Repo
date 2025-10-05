#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 100000;
vector<int> adj[MAXN + 1]; 
int dist[MAXN + 1];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    dist[start] = 1; 
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : adj[u]) {

            if (dist[v] == -1) {
                dist[v] = dist[u] + 1; 
                q.push(v);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    
    
    for (int i = 0; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    
    fill(dist, dist + n + 1, -1);
    
    
    bfs(0);
    cout<<"\n======================================\n";
    
    
    for (int i = 0; i <= n; ++i) {
    	if (dist[i] == -1){
        	cout<<"";
        	continue;
		}
        cout << i << "\t"<<dist[i] << '\n';
    }
    
    return 0;
}
