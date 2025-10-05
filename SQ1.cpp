#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main(){
        long n;
        cin >>n;
        long a[n];
        long max = LONG_MIN;
        long min = LONG_MAX;
        long test;
        for (long j=0;j<n;j++){
            cin >> a[j];
            if (a[j] > max) {
                max = a[j];
                test = max-min;
            }
            if (a[j] < min)    min = a[j];
        }

        cout << test;
}
