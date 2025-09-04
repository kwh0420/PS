#include <bits/stdc++.h>
using namespace std;
long long int n,m;
long long int arr[100002];
int main() {
    cin>>n>>m;
    for(long long int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n);
    long long int start=0,end=0;
    long long int minval = 1e18;
    while(end<n) {
        long long int k= arr[end]-arr[start];
        if (k<m) {
            end++;
        }
        else if (k==m) {
            cout << m;
            exit(0);
        }
        else {
            minval=min(minval,k);
            start++;
        }
    }
    cout << minval;
}