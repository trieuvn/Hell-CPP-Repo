#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 2*1e6+5;

int T,n,m,p,d;
typedef struct Gate{
    int l;
    int v;
    int t;
}gate;

int l[MAX], v[MAX], t[MAX];
gate lst[MAX];

bool cmp(gate A, gate B){
    if (A.v == B.v){
        return A.t < B.t;
    }
    return A.v < B.v;
}

void reset(){
    gate trash;
    trash.l = LLONG_MAX;
    trash.v = LLONG_MAX;
    trash.t = LLONG_MAX;
    for (int i=0;i<MAX;i++){
        lst[i] = trash;
        //checkpoint[i] = 0;
        //vis[i] = 0;
    }
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>T;
    while (T--){
        vector<int> vis(MAX,false);
        vector<int> checkpoint(MAX,0);
        reset();
        vis[1] = true;
        cin>>n>>m>>p>>d;
        for (int i=0;i<m;i++){
            cin>>lst[i].l;
            cin>>lst[i].v;
            cin>>lst[i].t;
        }

        int Max = 0;

        sort(lst,lst+m,cmp);
        checkpoint[1] = p;
        bool iswin = false;
        for (int i=0;i<m;i++){
            if (checkpoint[lst[i].v] <= lst[i].l || vis[lst[i].v] == false) continue;
            vis[lst[i].v] = true;
            vis[lst[i].t] = true;

            int u;
            if (checkpoint[lst[i].v] <= lst[i].l){
                u = checkpoint[lst[i].v]/2;
            }else{
                u = checkpoint[lst[i].v] + (lst[i].l)/2;
            }
            checkpoint[lst[i].t] = max(checkpoint[lst[i].t], u);

            //Max = max(Max, checkpoint[lst[i].t]);

            if (lst[i].t == n && checkpoint[lst[i].t] >= d){
                iswin = true;
                //cout<<checkpoint[lst[i].t]<<" ";
                Max = max(Max, checkpoint[lst[i].t]);
            }
        }

        if (iswin){
            cout<<Max<<"\n";
        }else{
            cout<<"Impossible\n";
        }

    }
}

