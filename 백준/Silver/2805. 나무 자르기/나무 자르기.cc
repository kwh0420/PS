#include <bits/stdc++.h>
using namespace std;
long long int N,M;
long long int arr[1000002];
int main() {
    cin>>N>>M;
    for(long long int i=0;i<N;i++) {
        cin>>arr[i];
    }
    sort(arr,arr+N);
    long long int lo = 0;
    long long int hi = arr[N-1]+1;
    while (lo < hi) {
        long long int mid = (lo + hi+1)/2;
        long long int maxval=0;
        for(long long int i=0;i<N;i++) {
            if (arr[i]-mid>0)
            maxval +=arr[i]-mid;
        }
        if (maxval==M) {
            lo=mid;
        }
        else if (maxval<M) {
            hi=mid-1;
        }
        else {
            lo=mid;
        }
    }
    cout << hi;
}