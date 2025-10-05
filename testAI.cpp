#include <bits/stdc++.h>
using namespace std;
 
// S? bit (v?i a[i] < 2^30, d�ng 31 bit: t? 30 xu?ng 0)
const int BITS = 31;
 
// Node c?a trie
struct Node {
    int cnt;
    int child[2]; // ch? s? c?a con tr�i v� ph?i, -1 n?u chua c�
    Node() : cnt(0) {
        child[0] = child[1] = -1;
    }
};
 
// Trie to�n c?c
vector<Node> trie;
 
// Kh?i t?o trie v?i node g?c
void initTrie() {
    trie.clear();
    trie.push_back(Node());
}
 
// Ch�n s? num v?i t?n s? freq v�o trie
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
// M?c ti�u: d?m s? c�c s? y (dang c� trong trie) sao cho
// (1) y >= L, v?i L = 2*x
// (2) y ch?a t?t c? c�c bit 1 c?a x, t?c (y & x) == x.
//
// Ch�ng ta duy?t c�c bit t? BITS-1 xu?ng 0, v?i tr?ng th�i:
//    - node: ch? s? hi?n t?i trong trie
//    - pos: bit hi?n h�nh
//    - tight: (bool) cho bi?t prefix c?a y dang �ch?t� so v?i L hay d� vu?t
//
// Stack luu tr?ng th�i (node, pos, tight, curPrefix).
struct State {
    int node, pos;
    bool tight;
    int cur; // gi� tr? ph?n prefix d� ch?n (kh�ng c?n d�ng n?u ta ch? c?n d?m khi r?i l�)
};
 
// H�m query: tr? v? t?ng cnt c?a c�c s? y trong trie th?a c�c r�ng bu?c v?i cho tru?c x v� L=2*x.
long long queryForX_iterative(int x) {
    int L = 2 * x; // lower bound
    long long res = 0;
    // Stack d�ng vector (s? c� k�ch thu?c t?i da 32)
    vector<State> st;
    st.reserve(64);
    // tr?ng th�i kh?i d?u: b?t d?u ? node 0, pos = BITS-1, tight=true.
    st.push_back({0, BITS-1, true, 0});
    
    while (!st.empty()){
        State s = st.back();
        st.pop_back();
        int node = s.node, pos = s.pos;
        bool tight = s.tight;
        // N?u d� duy?t h?t c�c bit:
        if(pos < 0){
            res += trie[node].cnt;
            continue;
        }
        // X�t bit c?a x v� L t?i pos
        int bitX = (x >> pos) & 1;
        int bitL = (L >> pos) & 1;
        
        // N?u x c� bit 1 th� y b?t bu?c ph?i c� 1 t?i pos.
        if(bitX == 1){
            int nxt = trie[node].child[1];
            if(nxt == -1) continue; // kh�ng c� s? n�o theo nh�nh n�y
            bool newTight;
            if(tight){
                // n?u bitL==1 th� v?n tight; n?u bitL==0 th� 1 > 0 => newTight = false.
                newTight = (bitL == 1);
            } else {
                newTight = false;
            }
            st.push_back({nxt, pos-1, newTight, 0});
        } else {
            // N?u x c� bit 0, ta c� th? ch?n 0 ho?c 1.
            // Option 1: ch?n bit 0 t?i pos.
            int nxt0 = trie[node].child[0];
            if(nxt0 != -1){
                bool newTight = tight;
                if(tight){
                    // N?u ch?n 0, c?n 0 >= bitL; di?u ki?n x?y ra khi bitL==0.
                    if(bitL == 0)
                        newTight = true;
                    else
                        newTight = false; // kh�ng tho? lower-bound, n�n nh�nh n�y ch? du?c duy?t n?u n� �free� (tight==false)
                }
                st.push_back({nxt0, pos-1, newTight, 0});
            }
            // Option 2: ch?n bit 1 t?i pos.
            int nxt1 = trie[node].child[1];
            if(nxt1 != -1){
                bool newTight;
                if(tight){
                    // N?u ch?n 1, th� ph?i c� 1 >= bitL.
                    // N?u bitL==1, newTight = true; n?u bitL==0, 1 > 0 n�n newTight = false.
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
 
// Wrapper: query c�c s? y (d� c�n trong trie) th?a: y >= 2*x v� (y & x)== x.
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
 
    // T�nh t?n s? xu?t hi?n cho m?i gi� tr?.
    unordered_map<int, long long> freq;
    for (int a : arr)
        freq[a]++;
 
    // L?y danh s�ch c�c gi� tr? duy nh?t v� s?p x?p tang d?n.
    vector<int> vals;
    vals.reserve(freq.size());
    for (auto &p : freq)
        vals.push_back(p.first);
    sort(vals.begin(), vals.end());
 
    // X�y d?ng trie v?i t?t c? c�c gi� tr? (theo t?n s? c?a ch�ng)
    initTrie();
    for (auto &p : freq) {
        insertNum(p.first, p.second);
    }
 
    long long ans = 0;
    // V?i c?p (x,x): ch? th?a n?u x==0 (v� 0^0=0, v� 0<=0<=0)
    if(freq.find(0) != freq.end())
        ans += freq[0] * freq[0];
 
    // V?i c�c c?p (x,y) v?i x < y.
    // Duy?t theo th? t? tang d?n c?a x.
    for (int x : vals) {
        // Lo?i b? to�n b? s? x kh?i trie (d? ch? query c�c y > x).
        removeNum(x, freq[x]);
 
        // Query: d?m s? y (c�n trong trie) th?a y >= 2*x v� (y & x)== x.
        long long cnt = queryForX(x);
        ans += freq[x] * cnt;
    }
 
    cout << ans << "\n";
    return 0;
}

