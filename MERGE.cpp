#include<bits/stdc++.h>

using namespace std;

void Min(string x, string y){
	int i=0,j=0;
	while (x.size() != i && y.size() != j){
		if (x[i] < y[j]){
			cout<<x[i];
			i++;
		}else{
			cout<<y[j];
			j++;
		}
	}
	while (y.size() != j){
		cout<<y[j];
		j++;
	}
	while (x.size() != i){
		cout<<x[i];
		i++;
	}
}

void Max(string x, string y){
	int i=0,j=0;
	while (x.size() != i && y.size() != j){
		if (x[i] > y[j]){
			cout<<x[i];
			i++;
		}else{
			cout<<y[j];
			j++;
		}
	}
	while (y.size() != j){
		cout<<y[j];
		j++;
	}
	while (x.size() != i){
		cout<<x[i];
		i++;
	}
}

int main(){
	unsigned long x,y;
	cin>>x>>y;
	string a = to_string(x);
	string b = to_string(y);
	Min(a,b);
	cout<<"\n";
	Max(a,b);
	return 0;
}
