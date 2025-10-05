#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	unsigned int n,i,j,a=0,d=0;
	cin>>n;
	long long am[n],duong[n],x,Min,trai,phai;
	for (i=0;i<n;i++){
		cin>>x;
		if (x>=0){
			duong[d]=x;
			d++;
		}else{
			am[a]=x;
			a++;
		}
	}
	sort(duong,duong+d);
	sort(am,am+a);
	unsigned int q;
	cin>>q;
	for (i=0;i<q;i++){
		cin>>x;
		if (x >= 0){
			for (j=0;j<d;j++){
			if (duong[j]>=x)
				break;
			}
			if (j==0){
				phai = x-duong[j];
				if (phai<0)	phai*=-1;
				cout<<phai<<"\n";
				continue;
			}
			trai = x-duong[j-1];
			phai = x-duong[j];
			if (trai<0)	trai*=-1;
			if (phai<0)	phai*=-1;
			if (trai < phai){
				cout<<trai<<"\n";
			}else{
				cout<<phai<<"\n";
			}
		}
		if (x < 0){
			for (j=0;j<a;j++){
			if (am[j]>=x)
				break;
			}
			if (j==0){
				phai = x-am[j];
				if (phai<0)	phai*=-1;
				cout<<phai<<"\n";
				continue;
			}
			trai = x-am[j-1];
			phai = x-am[j];
			if (trai<0)	trai*=-1;
			if (phai<0)	phai*=-1;
			if (trai < phai){
				cout<<trai<<"\n";
			}else{
				cout<<phai<<"\n";
			}
		}
		
	}
	
    return 0;
}
