#include<bits/stdc++.h>

using namespace std;
long a[100001];
vector<long> t(1000000000,0);

void update(long v, long l, long r, long pos, long val){
	if (l == r){
		t[v] = val;
		
	}
	else{
		long m = (l + r)/2;
		if (pos <= m){
			update(2*v, l, m, pos, val);
		}else{
			update(2*v + 1, m+1, r, pos, val);
		}
		
		t[v] = max(t[2 * v], t[2*v+1]);
	}
}

long query(long v, long tl, long tr, long l, long r){
	if (l > r)	return 0;
	if (tl == l && tr == r){
		return t[v];
		trace[r+1] = v;
	}
	else{
		long tm = (tl + tr) / 2;
		long s1 = query(2*v,tl,tm,l, min(r,tm));
		long s2 = query(2*v+1, tm+1, tr, max(l,tm+1), r);
		return max(s1,s2);
	}
}

int main(){
	long n,i,MaxNum=LONG_MIN;
	long MaxPos=1;
	cin>>n;
	for (i=1;i<=n;i++){
		cin>>a[i];
		MaxNum = max(MaxNum,a[i]);
	
	}
	update(1,0,MaxNum,a[1],1);
	long d;
	for (i=2;i<=n;i++){
		d = query(1,0,MaxNum,1,a[i]-1)+1;
		if ()
		update(1,0,MaxNum,a[i],d);
		for (j=i-1;j>=1;j--){
			if (t[a[j]] == d-1){
				trace[i] = j;
			}
		}
		
	}
	for (i=t[1];i!=-1;i=trace[i]){
		cout<<
	}
	cout<<t[1];
}
