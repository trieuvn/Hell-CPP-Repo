#include<bits/stdc++.h>

using namespace std;
const int sl = 1e5+5;

int a[sl];

map<int,int> t[sl];

int n,q;

int blocksize = 400;

int getBlock(int idx){
	return (idx-1)/blocksize +1;
}

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	//blocksize = sqrt(n)+1;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		t[getBlock(i)][a[i]]++;
	}

	for (int i=0;i<q;i++){
		int l,r,x;
		cin>>l>>r>>x;
		int u = getBlock(l);
		int v = getBlock(r);
		//cout<<u<<" "<<v<<"\n";
		if (u == v){
			map <int,int> s;
			int sum = 0;
			for (int i=l;i<=r;i++){
				s[a[i]]++;				
			}
			for (auto it = s.begin();it!=s.end();it++){
				if ((*it).second == x){
					sum++;
				}
			}
			cout<<sum<<"\n";
			continue;
		}
		int sum = 0;
		map <int,int> s;
		for (int i=u+1;i<v;i++){
			for (auto it = t[i].begin();it!=t[i].end();it++){
				s[(*it).first] += (*it).second;
			}
		}
		
		for (int i=l;i<=u*blocksize;i++){					
			s[a[i]]++;
		}
		for (int i=r;i>(v-1)*blocksize;i--){
			s[a[i]]++;
		}
		for (auto it = s.begin();it!=s.end();it++){
			//cout<<"DSDSD";
			if ((*it).second == x){
				sum++;
			}
		}									
		cout<<sum<<"\n";
	}
	
}
