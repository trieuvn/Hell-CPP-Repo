#include<bits/stdc++.h>

using namespace std;

int main(){
	string a,b;
	cin>>a>>b;
	unsigned long xa=0,xb=0;
	int check=0;
	for (int i=0;i<a.size() ;i++){
		if (a[i] == '.'){
			check=1;
		}
		else if (check == 1 && a[i] != '0'){
			check==2;
			break;
		}else
			xa=xa*10+(a[i] - '0');
	}
	if (check == 2)
	check=0;
	for (int i=0;i<b.size() ;i++){
		if (a[i] == '.'){
			check=1;
		}
		else if (check == 1 && a[i] != '0'){
			xb++;
			break;
		}else
			xb=xb*10+(a[i] - '0');
	}
	unsigned long s=0;
	
	cout<<xa<<xb;
	return 0;
}
