#include<bits/stdc++.h>
#define int long long

using namespace std;

typedef struct choice{
	int w;
	int v;
}choice;

bool cmp(choice A, choice B){
	if (A.w == B.w){
		return A.v > B.v;
	}
	return A.w < B.w;
}

int n,s;
vector<choice> dachon;
vector<choice> dabo;

signed main(){
	cin>>n>>s;
	int w,v,c;
	int curw = 0;
	int totalval = 0;
	for (int i=0;i<n;i++){
		choice in;
		cin>>w>>v>>c;
		in.w = w;
		in.v = v;
		if (c == 1){
			curw += in.w;
			totalval += in.v;
			dachon.push_back(in);
		}
		if (c == 0){
			dabo.push_back(in);
		}
	}
	
	int Max = totalval;
	sort(dachon.begin(),dachon.end(),cmp);
	sort(dabo.begin(),dabo.end(),cmp);
	int j = 0;
	int bestChoiceVal = 0;
	for (choice cur : dachon){
		int tempw = curw;
		int tempv = totalval;
		tempw -= cur.w;
		tempv -= cur.v;
		
//		for (choice bo : dabo){
//			if (bo.w + tempw <= s){
//				Max = max(Max, tempv + bo.v);
//			}
//		}
		
		bool isloop = true;
		
		while (j < dabo.size() && dabo[j].w + tempw <= s){
			bestChoiceVal = max(bestChoiceVal, dabo[j].v);
			j++;
		}
		Max = max(Max, tempv + bestChoiceVal);
	}
	
	cout<<Max;
}
