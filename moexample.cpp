#include<bits/stdc++.h>
#define int int64_t

using namespace std;

const int MAXN = 1e5+5;
const int BLK = 320; // Kích thu?c block ~ sqrt(N)

int n, q;
int a[MAXN];
int cnt[MAXN]; // Ð?m s? l?n xu?t hi?n c?a giá tr? v
int fof[MAXN]; // Ð?m có bao nhiêu s? có cùng t?n su?t k
int ans[MAXN];

// Ð?nh nghia struct theo yêu c?u
typedef struct {
    int l, r, x, id;
} Query;

Query queries[MAXN];

// Hàm so sánh riêng d? sort thay vì dùng operator
bool cmp(Query a, Query b) {
    int blk_a = a.l / BLK;
    int blk_b = b.l / BLK;
    
    if (blk_a != blk_b) return blk_a < blk_b;
    
    // T?i uu zig-zag: Block ch?n tang R, Block l? gi?m R
    if (blk_a % 2 == 0) return a.r < b.r;
    return a.r > b.r;
}

void add(int idx) {
    int val = a[idx];
    int sl = cnt[val];
    
    if (sl > 0) fof[sl]--; // Gi?m d?m ? t?n su?t cu
    cnt[val]++;
    fof[cnt[val]]++;       // Tang d?m ? t?n su?t m?i
}

void remove(int idx) {
    int val = a[idx];
    int sl = cnt[val];
    
    fof[sl]--;             // Gi?m d?m ? t?n su?t cu
    cnt[val]--;
    if (cnt[val] > 0) fof[cnt[val]]++; // Tang d?m ? t?n su?t m?i
}

signed main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < q; i++) {
        cin >> queries[i].l >> queries[i].r >> queries[i].x;
        queries[i].id = i;
    }

    // Truy?n hàm cmp vào sort
    sort(queries, queries + q, cmp);

    int curL = 1;
    int curR = 0;

    for (int i = 0; i < q; i++) {
        int L = queries[i].l;
        int R = queries[i].r;
        int X = queries[i].x;

        // Di chuy?n 2 con tr? Mo
        while (curL > L) add(--curL);
        while (curR < R) add(++curR);
        while (curL < L) remove(curL++);
        while (curR > R) remove(curR--);

        // K?t qu? là s? lu?ng ph?n t? có t?n su?t dúng b?ng X
        ans[queries[i].id] = fof[X];
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << "\n";
    }
}
