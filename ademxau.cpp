#include<bits/stdc++.h>
#define int long long 

using namespace std;

string S, T;
vector<int> lps;

void build_lps() {
    int m = T.length();
    lps.resize(m, 0); 
    
    int len = 0; 
    int i = 1; 

    while (i < m) {
        if (T[i] == T[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin >> S >> T;
	
	int n = S.length();
	int m = T.length();
	
	if (m == 0 || m > n) {
		cout << 0;
		return 0;
	}
	
	build_lps();
	
	int count = 0;
	int i = 0;
	int j = 0;
	
	while (i < n) {
		if (T[j] == S[i]) {
			i++;
			j++;
		}
		
		if (j == m) {
			count++;
			j = lps[j - 1];
		} else if (T[j] != S[i]) {
			if (j != 0) {
				j = lps[j - 1];
			} else {
				i++;
			}
		}
	}
	
	cout << count;
}
