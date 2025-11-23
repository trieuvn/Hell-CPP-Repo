#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1e5+5;

int n,k;
vector<pair<int,int>> adj[MAX];
int cafeList[MAX];
bool isCafe[MAX];
int shortest[MAX];
vector<int> res(MAX, LLONG_MAX);

void DS(int start){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,start});

    while (!pq.empty()){
        int cost = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        for (pair<int,int> child : adj[u]){
            int v = child.first;
            int w = child.second;
            int newcost = w + cost;
            if (newcost < shortest[v]){
                shortest[v] = newcost;
                pq.push({newcost,v});

            }
        }
    }
}

void DS2(int start){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,start});

    while (!pq.empty()){
        int cost = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        for (pair<int,int> child : adj[u]){
            int v = child.first;
            int w = child.second;
            int newcost = w + cost;
            if (newcost < shortest[v]){
                if (v == start) continue;
                    shortest[v] = newcost;
                    pq.push({newcost,v});

            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    //memset(shortest,10000,sizeof(shortest));
    cin>>n>>k;
    int u,v,w;
    for (int i=0;i<n-1;i++){
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    for (int i=0;i<k;i++){
        cin>>cafeList[i];
        isCafe[cafeList[i]] = true;
    }

    for (int i=0;i<2;i++){
        memset(shortest,10000,sizeof(shortest));
        DS(cafeList[i]);
        for (int j=1;j<=n;j++){
            if (j != cafeList[i]){
                res[j] = min(res[j], shortest[j]);
                //cout<<j<<" ";
            }
        }
    }

    for (int i=1;i<=n;i++){
        shortest[i] = res[i];
    }

    for (int i=2;i<k;i++){
        //memset(shortest,10000,sizeof(shortest));
        DS2(cafeList[i]);
        for (int j=1;j<=n;j++){
            if (j != cafeList[i]){
                res[j] = min(res[j], shortest[j]);
                //cout<<j<<" ";
            }
        }
    }

    for (int i=1;i<=n;i++){
        cout<<res[i]<<" ";
    }
}

