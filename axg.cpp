#include<bits/stdc++.h>

using namespace std;

int T;

int w,c;


int trace(int n, int x){
	if (n==0){
		if (x==0)	return 1;
		return 0;
	}
	int sum = 0;
	for (int i=0;i<=c;i++){
		sum += trace(n-1,x-1000*pow(10,i));
		sum += trace(n-1,x-2000*pow(10,i));
		sum += trace(n-1,x-3000*pow(10,i));
		sum += trace(n-1,x-5000*pow(10,i));
	}
	return sum;
}

signed main(){
	cin>>T;
	while (T--){
		cin>>w>>c;
		int s = 0;
		int temp = w;
		for (int i=c;i>=0;i--){
			int x = 5000*pow(10,i);
			while (w >= x){
				w-=x;
				s++;
			}
			x = 3000*pow(10,i);
			while (w >= x){
				w-=x;
				s++;
			}
			x = 2000*pow(10,i);
			while (w >= x){
				w-=x;
				s++;
			}
			x = 1000*pow(10,i);
			while (w >= x){
				w-=x;
				s++;
			}
		}
		if (w == 0)	cout<<s<<" "<<trace(s,temp);
		else cout<<0;
	}
}
