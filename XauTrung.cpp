#include<string.h>
#include<iostream>

using namespace std;

int main(){
	char a[20];
	unsigned long tong=0;
	cin>>a;
	int i=0;
	while(i<strlen(a)){
		if(a[i]=='M'){
			tong+=1000;
			i++;
		}else
		if(a[i]=='C'){
			if(a[i+1]=='M'){
				tong+=900;
				i+=2;				
			}else
			if(a[i+1]=='D'){
				tong+=400;
				i+=2;
			}else{
				tong+=100;
				i++;
			}			
		}else
		if(a[i]=='D'){
			tong+=500;
			i++;
		}else
		if(a[i]=='X'){
			if(a[i+1]=='C'){
				tong+=90;
				i+=2;				
			}else
			if(a[i+1]=='L'){
				tong+=40;
				i+=2;
			}else{
				tong+=10;
				i++;
			}			
		}else
		if(a[i]=='L'){
			tong+=50;
			i++;
		}else
		if(a[i]=='I'){
			if(a[i+1]=='X'){
				tong+=9;
				i+=2;				
			}else
			if(a[i+1]=='V'){
				tong+=4;
				i+=2;
			}else{
				tong+=1;
				i++;
			}			
		}else
		if(a[i]=='V'){
			tong+=5;
			i++;
		}
			
		
	}
	cout<<tong;
	return 0;
}
