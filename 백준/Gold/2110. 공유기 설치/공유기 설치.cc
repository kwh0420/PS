#include <bits/stdc++.h>
using namespace std;
long long int N;
long long int C;
long long int arr[200001];
int solve(int len) {
    int idx=0;
    int cnt=0;
    while (idx != N) {
        idx = lower_bound(arr,arr+N,arr[idx]+len)-arr;
        cnt++;
    }
    return cnt>=C;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> C;
    for (long long int i=0;i<N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+N);
    long long int lo=0;
    long long int hi =1e9;
    long long int mid = (hi+lo)/2;

    while (lo<hi) {
        mid = (hi+lo+1)/2;
        if (solve(mid)) {
            lo=mid;
        }
        else {
            hi=mid-1;
        }
    }
    cout << lo;
}