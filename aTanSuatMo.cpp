#include<bits/stdc++.h>
#define int int64_t

using namespace std;

typedef struct Query{
	int l;
	int r;
	int x;
	int idx;
}Query;

const int MAX = 1e6+5;
const int BLOCKSIZE = 317;

int n,q;
int l,r,x,idx;

int sl[MAX];
int tansuat[MAX];
int a[MAX];
Query truyvan[MAX];
int res[MAX];

bool cmp(Query a, Query b){
	int bla = a.l/BLOCKSIZE;
	int blb = b.l/BLOCKSIZE;
	if (bla != blb)	return bla < blb;
	
	if (bla % 2 == 0)	return a.r < b.r;
	return a.r > b.r;
}

void add(int idx){
	
	if (sl[a[idx]] > 0)	tansuat[sl[a[idx]]]--;
	sl[a[idx]]++;
	tansuat[sl[a[idx]]]++;
}

void remove(int idx){
	tansuat[sl[a[idx]]]--;
	sl[a[idx]]--;
	if (sl[a[idx]] > 0) tansuat[sl[a[idx]]]++;
}

signed main(){
	cin>>n>>q;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for (int i=0;i<q;i++){
		cin>>l>>r>>x;
		truyvan[i].l = l;
		truyvan[i].r = r;
		truyvan[i].x = x;
		truyvan[i].idx = i;
	}
	
	sort(truyvan,truyvan+q,cmp);
	
	int tl = 1;
	int tr = 0;
	
	for (int i=0;i<q;i++){
		l = truyvan[i].l;
		r = truyvan[i].r;
		x = truyvan[i].x;
		idx = truyvan[i].idx;
		
		while (tl < l) remove(tl++);
		while (tr > r) remove(tr--);
		while (tl > l)	add(--tl);
		while (tr < r) add(++tr);
		
		res[idx] = tansuat[x];
	}
	
	for (int i=0;i<q;i++){
		cout<<res[i]<<"\n";
	}
}
