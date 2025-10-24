#include<bits/stdc++.h>
#define int unsigned long long

using namespace std;

const int MAX = 1e5+5;

typedef struct vt{
	int ct;
	int money;
}vt;

int n,k;
int ct[MAX];
int money[MAX];
vt tb[MAX];


bool comp(vt a, vt b){
	if (a.money * b.ct == b.money * a.ct){
		return a.ct > b.ct;
	}
		
	return a.money * b.ct < b.money * a.ct;
}

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	int max1 = 1;
	int max2 = -1;
	for (int i=0;i<n;i++){
		cin>>ct[i];
	}
	for (int i=0;i<n;i++){
		cin>>money[i];
	}
	for (int i=0;i<n;i++){
		tb[i].ct = ct[i];
		tb[i].money = money[i];
	}
	sort(tb,tb+n,comp);
	for (int i=0;i<n;i++){
		//cout<<tb[i].ct<<" ";
	}
//	for (int i=2;i<=n;i++){
//		if (ct[max1]*money[i] <= ct[i]*money[max1]){
//			if (ct[max1] < ct[i] || max1==-1)
//				max1 = i;
//		}
//	}
//	for (int i=1;i<=n;i++){
//		if (i == max1) continue;
//		if ((ct[max2]*money[i] <= ct[i]*money[max2]) || max2==-1){
//			if (ct[max2] < ct[i] || max2==-1)
//				max2 = i;
//		}
//	}
//	int count = 0;
//	for (int i=1;i<=n;i++){
//		if (i == max1) continue;
//		if (ct[max2]*money[i] == ct[i]*money[max2]){
//			count++;
//		}
//	}
//	if (count >1){
//		for (int i=1;i<=n;i++){
//			if (i == max1) continue;
//			
//		}
//	}
	cout<<tb[0].ct+tb[1].ct<<" "<<tb[0].money+tb[1].money;
}
    
