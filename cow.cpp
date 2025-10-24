#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1e5+5;

int n,p;
int c[MAX];
vector<pair<int,int>> adj[MAX];


int DS(int start){
	vector<int> minTo(MAX, LLONG_MAX);
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	
    // L?I 1: C?n kh?i t?o chi ph� cho di?m b?t d?u
    minTo[start] = c[start]; 
	pq.push({c[start],start});
	
	while (!pq.empty()){
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

        // L?I 2: Thi?u ki?m tra. N?u cost > minTo[cur] th� d�y l�
        // m?t tr?ng th�i cu trong queue, n�n b? qua.
        if (cost > minTo[cur]) continue; 

//		if (cost <= minTo[cur]){ // �o?n n�y b? comment v� logic cung sai
//			minTo[cur] = cost;
//		}
		
		for (pair<int,int> br : adj[cur]){
			int u = br.first;
			int value = br.second;
            
            // L?I 3: Logic c?p nh?t sai
            int new_cost = cost + c[u] + value; // T�nh chi ph� m?i
			// if (cost+c[u]+value > minTo[u]) continue; // ��y l� logic sai
            
            if (new_cost < minTo[u]) { // Logic Dijkstra chu?n
			    minTo[u] = new_cost;
			    pq.push({new_cost, u});
            }
		}
	}
	int sum = 0;
	for (int i=1;i<=n;i++){
        // L?I 4: N?u kh�ng s?a L?I 1, minTo[start] s? l� LLONG_MAX
        // l�m cho t?ng b? sai (tr�n s?).
		sum+=minTo[i];
	}
	return sum+c[start];
}

signed main(){
	// ... (ph?n main l� d�ng) ...
	cin>>n>>p;
	for (int i=1;i<=n;i++){
		cin>>c[i];
	}
	int u,v,value;
	for (int i=0;i<p;i++){
		cin>>u>>v>>value;
		adj[u].push_back({v,value});
		adj[v].push_back({u,value});
	}
	
	int Min = DS(1);
	for (int i=2;i<=n;i++){
		Min = min(Min, DS(i));
	}
	cout<<Min;
	
}
