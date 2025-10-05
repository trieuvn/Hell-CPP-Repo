
#include<stdio.h>
#include<iostream>

using namespace std;

int Max(int a[], int n){
    int max=a[0];
    for (int i=1;i<n;i++){
        if(a[i]>max)
            max=a[i];
    }
    return max;
}

int main() {
    int n,a[100];
    int k[100];
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a[i];
        k[i]=1;
    }
    int max=0;
    
    for (int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if (a[j]>a[i] && k[j]<k[i]+1)
                k[j]=k[i]+1;
            if(max<k[j])
        		max=k[j];
        }
        
    }
    
    cout<<max;
    
    return 0;
}
