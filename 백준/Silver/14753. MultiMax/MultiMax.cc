#include <bits/stdc++.h>
using namespace std;
long long int arr[10002];
 int main() {
     ios::sync_with_stdio(false);
     cin.tie(nullptr);

    long long int n;
    cin >> n;
    for (long long int i=0 ; i<n; i++) {
        long long int k;
        cin >> k;
        arr[i]=k;
    }
     sort(arr,arr+n);
    cout << max(max(arr[0]*arr[1],arr[n-1]*arr[n-2]),max((arr[0]*arr[1]*arr[n-1]),arr[n-1]*arr[n-2]*arr[n-3]));
}