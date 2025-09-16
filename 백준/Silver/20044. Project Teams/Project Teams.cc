#include <bits/stdc++.h>
using namespace std;
int N;
int arr[100000];
int main() {
    cin >> N;
    N*=2;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr,arr+N);
    int minval =1e9;
    for (int i = 0; i <= N/2-1; i++) {
        minval = min(minval, arr[i]+arr[N-i-1]);
    }
    cout << minval;
}