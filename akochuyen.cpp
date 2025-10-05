#include<bits/stdc++.h>

using namespace std;

signed main(){
	long double u,v;
	cin>>u>>v;
	long double canh = sqrt(u*u + v*v);
	cout<<fixed<<setprecision(2)<<canh*canh/4;
}
