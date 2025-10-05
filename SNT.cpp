#include <bits/stdc++.h>
#include<iostream>
#include<math.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    int a[1001], l[1001];
    for (int i=0;i<n;i++){
        cin>>a[i];
        l[i]=1;
    }
    
    for (int i=0;i<n;i++){
        int max =0;
        for (int j=0;j<i;j++){
            if (a[i]<a[j] && l[j]<l[i]+1)
                l[j]=l[i]+1;
        }
        
    }
   
    
    return 0;
}
