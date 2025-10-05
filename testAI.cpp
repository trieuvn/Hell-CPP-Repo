#include <bits/stdc++.h>
using namespace std;
 
// S? bit (v?i a[i] < 2^30, dùng 31 bit: t? 30 xu?ng 0)
const int BITS = 31;
 
// Node c?a trie
struct Node {
    int cnt;
    int child[2]; // ch? s? c?a con trái và ph?i, -1 n?u chua có
    Node() : cnt(0) {
        child[0] = child[1] = -1;
    }
};
 
// Trie toàn c?c
vector<Node> trie;
 
// Kh?i t?o trie v?i node g?c
void initTrie() {
    trie.clear();
    trie.push_back(Node());
}
 
// Chèn s? num v?i t?n s? freq vào trie
void insertNum(int num, int freq) {
    int cur = 0;
    trie[cur].cnt += freq;
    for (int pos = BITS - 1; pos >= 0; pos--) {
        int bit = (num >> pos) & 1;
        if (trie[cur].child[bit] == -1) {
            trie[cur].child[bit] = trie.size();
            trie.push_back(Node());
        }
        cur = trie[cur].child[bit];
        trie[cur].cnt += freq;
    }
}
 
// Lo?i b? s? num v?i t?n s? freq kh?i trie
void removeNum(int num, int freq) {
    int cur = 0;
    trie[cur].cnt -= freq;
    for (int pos = BITS - 1; pos >= 0; pos--) {
        int bit = (num >> pos) & 1;
        cur = trie[cur].child[bit];
        trie[cur].cnt -= freq;
    }
}
 
// --- Iterative DFS cho query ---
// M?c tiêu: d?m s? các s? y (dang có trong trie) sao cho
// (1) y >= L, v?i L = 2*x
// (2) y ch?a t?t c? các bit 1 c?a x, t?c (y & x) == x.
//
// Chúng ta duy?t các bit t? BITS-1 xu?ng 0, v?i tr?ng thái:
//    - node: ch? s? hi?n t?i trong trie
//    - pos: bit hi?n hành
//    - tight: (bool) cho bi?t prefix c?a y dang “ch?t” so v?i L hay dã vu?t
//
// Stack luu tr?ng thái (node, pos, tight, curPrefix).
struct State {
    int node, pos;
    bool tight;
    int cur; // giá tr? ph?n prefix dã ch?n (không c?n dùng n?u ta ch? c?n d?m khi r?i lá)
};
 
// Hàm query: tr? v? t?ng cnt c?a các s? y trong trie th?a các ràng bu?c v?i cho tru?c x và L=2*x.
long long queryForX_iterative(int x) {
    int L = 2 * x; // lower bound
    long long res = 0;
    // Stack dùng vector (s? có kích thu?c t?i da 32)
    vector<State> st;
    st.reserve(64);
    // tr?ng thái kh?i d?u: b?t d?u ? node 0, pos = BITS-1, tight=true.
    st.push_back({0, BITS-1, true, 0});
    
    while (!st.empty()){
        State s = st.back();
        st.pop_back();
        int node = s.node, pos = s.pos;
        bool tight = s.tight;
        // N?u dã duy?t h?t các bit:
        if(pos < 0){
            res += trie[node].cnt;
            continue;
        }
        // Xét bit c?a x và L t?i pos
        int bitX = (x >> pos) & 1;
        int bitL = (L >> pos) & 1;
        
        // N?u x có bit 1 thì y b?t bu?c ph?i có 1 t?i pos.
        if(bitX == 1){
            int nxt = trie[node].child[1];
            if(nxt == -1) continue; // không có s? nào theo nhánh này
            bool newTight;
            if(tight){
                // n?u bitL==1 thì v?n tight; n?u bitL==0 thì 1 > 0 => newTight = false.
                newTight = (bitL == 1);
            } else {
                newTight = false;
            }
            st.push_back({nxt, pos-1, newTight, 0});
        } else {
            // N?u x có bit 0, ta có th? ch?n 0 ho?c 1.
            // Option 1: ch?n bit 0 t?i pos.
            int nxt0 = trie[node].child[0];
            if(nxt0 != -1){
                bool newTight = tight;
                if(tight){
                    // N?u ch?n 0, c?n 0 >= bitL; di?u ki?n x?y ra khi bitL==0.
                    if(bitL == 0)
                        newTight = true;
                    else
                        newTight = false; // không tho? lower-bound, nên nhánh này ch? du?c duy?t n?u nó “free” (tight==false)
                }
                st.push_back({nxt0, pos-1, newTight, 0});
            }
            // Option 2: ch?n bit 1 t?i pos.
            int nxt1 = trie[node].child[1];
            if(nxt1 != -1){
                bool newTight;
                if(tight){
                    // N?u ch?n 1, thì ph?i có 1 >= bitL.
                    // N?u bitL==1, newTight = true; n?u bitL==0, 1 > 0 nên newTight = false.
                    newTight = (bitL == 1);
                } else {
                    newTight = false;
                }
                st.push_back({nxt1, pos-1, newTight, 0});
            }
        }
    }
    return res;
}
 
// Wrapper: query các s? y (dã còn trong trie) th?a: y >= 2*x và (y & x)== x.
inline long long queryForX(int x) {
    return queryForX_iterative(x);
}
 
// --- Main ---
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
 
    // Tính t?n s? xu?t hi?n cho m?i giá tr?.
    unordered_map<int, long long> freq;
    for (int a : arr)
        freq[a]++;
 
    // L?y danh sách các giá tr? duy nh?t và s?p x?p tang d?n.
    vector<int> vals;
    vals.reserve(freq.size());
    for (auto &p : freq)
        vals.push_back(p.first);
    sort(vals.begin(), vals.end());
 
    // Xây d?ng trie v?i t?t c? các giá tr? (theo t?n s? c?a chúng)
    initTrie();
    for (auto &p : freq) {
        insertNum(p.first, p.second);
    }
 
    long long ans = 0;
    // V?i c?p (x,x): ch? th?a n?u x==0 (vì 0^0=0, và 0<=0<=0)
    if(freq.find(0) != freq.end())
        ans += freq[0] * freq[0];
 
    // V?i các c?p (x,y) v?i x < y.
    // Duy?t theo th? t? tang d?n c?a x.
    for (int x : vals) {
        // Lo?i b? toàn b? s? x kh?i trie (d? ch? query các y > x).
        removeNum(x, freq[x]);
 
        // Query: d?m s? y (còn trong trie) th?a y >= 2*x và (y & x)== x.
        long long cnt = queryForX(x);
        ans += freq[x] * cnt;
    }
 
    cout << ans << "\n";
    return 0;
}

