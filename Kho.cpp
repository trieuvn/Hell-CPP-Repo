#include <bits/stdc++.h>
#include<math.h>
#include<iostream>

using namespace std;

int main() {
    long n;
    long int a[1001];
    int l[1001];
    cin>>n;
    for (long i=0;i<n;i++){
        cin>>a[i];
        l[i]=1;
    }
    int max=0;
    for (long i=0;i<n;i++){
       
        for (long j=i+1;j<n;j++){
            if (a[j]>a[i] && l[j]<l[i]+1)
                l[j]=l[i]+1;
        }
        if (max<l[i])
            max=l[i];
    }
    cout<<max;
    
    return 0;
}
