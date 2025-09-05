#include <bits/stdc++.h>
using namespace std;
long long int arr[100002];
long long int n;
int main() {
    cin >>n;
    for (long long int i = 0; i < n; i++) {
        cin >>arr[i];
    }
    sort(arr, arr + n);
    long long int maxval=0;
    long long int maxvalval=-(1ll<<62)-1;
    long long int k=0;
    for (long long int i = 0; i < n; i++) {
        if (i==0||arr[i-1]==arr[i]) {
            k++;
        }
        else {
            if (k>maxval) {
                maxval=k;
                maxvalval=arr[i-1];
            }
            k=1;
        }
    }
    if (k>maxval) {
        maxval=k;
        maxvalval=arr[n-1];
    }
    cout << maxvalval;

}