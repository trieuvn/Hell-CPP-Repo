#include<bits/stdc++.h>

using namespace std;

const int MAX = 1e6+5;

int k,m,input;
vector<int> d;
vector<int> trace(MAX, -2);
int so[MAX];

bool vis[MAX];

string bfs(){
	
	if (m==1){
		for (int digit : d){
			if (digit > 0){
				return to_string(digit);
			}
		}
		return "-1";
	}
	
	
	queue<int> q;
	for (int digit : d){
		if (digit == 0) continue;
		int pd = digit%m;
		if (pd == 0){
			return to_string(digit);
		}
		
		if (vis[pd] == false){
			vis[pd] = true;
			q.push(pd);
			trace[pd] = -2;
			so[pd] = digit;
		}
	}
	
	while (!q.empty()){
		int x = q.front();
		q.pop();
		for (int digit : d){
			int pd = (x*10+digit)%m;
			if (pd == 0){
				string ans = to_string(digit);
				for (int i=x;i!=-2;i=trace[i]){
					ans += to_string(so[i]);
				}
				reverse(ans.begin(),ans.end());
				return ans;
			}
			if (vis[pd] == false){
				vis[pd] = true;
				q.push(pd);
				trace[pd] = x;
				so[pd] = digit;
			}
		}
	}
	
	return "-1";
}


signed main(){
	cin>>k>>m;
	for (int i=0;i<k;i++){
		cin>>input;
		d.push_back(input);
	}
	sort(d.begin(),d.end());
	cout<<bfs();
}
