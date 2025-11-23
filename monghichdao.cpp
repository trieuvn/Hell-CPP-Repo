#include<bits/stdc++.h>

using namespace std;

const int MAX = 1e5+5;
const int BLOCKSIZE = 370;

typedef struct Query{
	int l;
	int r;
	int idx;
}Query;

int n,q;
int sl;

int a[MAX];
int st[4*MAX];
Query tv[MAX];
multiset<int> p;
int ans[MAX];
int maxn;

bool cmp(Query a, Query b){
	int bla = a.l/BLOCKSIZE;
	int blb = b.l/BLOCKSIZE;
	if (bla != blb)	return bla < blb;
	if (bla%2 == 0)	return a.r < b.r;
	return a.r > b.r;
}

void update(int id, int tl, int tr, int pos, int val){
	if (tl > pos || tr < pos){
		return ;
	}
	if (tl == tr){
		st[id] += val;
		return ;
	}
	
	int tm = (tl + tr)/2;
	update(id<<1,tl,tm,pos,val);
	update((id<<1)+1,tm+1,tr,pos,val);
	
	st[id] = st[id<<1] + st[(id<<1)+1];
}

int get(int id, int tl, int tr, int l, int r){
	if (tl > r || tr < l){
		return 0;
	}
	if (tl >= l && tr <= r){
		return st[id];
	}
	
	int tm = (tl+tr)/2;
	int vl = get((id<<1),tl,tm,l,r);
	int vr = get((id<<1)+1,tm+1,tr,l,r);
	return vl + vr;
}

void addleft(int idx){
	int value = a[idx];
	int slval = get(1,0,maxn,0,value-1);
	sl += slval;
	update(1,0,maxn,value,1);
}

void addright(int idx){
	int value = a[idx];
	int slval = get(1,0,maxn,value+1,maxn);
	sl += slval;
	update(1,0,maxn,value,1);
	//cout<<idx<<" sl "<<sl;
}

void removeleft(int idx){
	int value = a[idx];
	update(1,0,maxn,value,-1);
	int slval = get(1,0,maxn,0,value-1);
	sl -= slval;
}

void removeright(int idx){
	int value = a[idx];
	update(1,0,maxn,value,-1);
	int slval = get(1,0,maxn,value+1,maxn);
	sl -= slval;
}

signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n>>q;
	for (int i=0;i<n;i++){
		cin>>a[i];
		maxn = max(maxn,a[i]);
	}
	maxn += 6;
	
	int l, r;
	for (int i=0;i<q;i++){
		cin>>l>>r;
		tv[i].l = l;
		tv[i].r = r;
		tv[i].idx = i;
	}
	
	sort(tv,tv+q,cmp);
	
	int cl = 0;
	int cr = 0;
	update(1,0,maxn,a[0],1);
	
	for (int i=0;i<q;i++){
		int l = tv[i].l-1;
		int r = tv[i].r-1;
		int idx = tv[i].idx;
		
		while (cl < l)	removeleft(cl++);
		while (cl > l)	addleft(--cl);
		while (cr > r)	removeright(cr--);
		while (cr < r)	addright(++cr);
		
		ans[idx] = sl;
		//cout<<idx<<" "<<sl<<"\n";
	}
	
	for (int i=0;i<q;i++){
		cout<<ans[i]<<"\n";
	}
}
