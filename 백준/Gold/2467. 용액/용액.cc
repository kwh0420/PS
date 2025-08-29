#include <bits/stdc++.h>
using namespace std;
long long int N;
long long int arr[100002];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (long long int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    long long int minval=1e18;
    long long int low = 0, high = N-1;
    int ans1=0,ans2=0;
    while (low < high) {
        long long int sum= arr[low] + arr[high];
        if (abs(sum)<abs(minval)) {
            minval = sum;
            ans1 = arr[low];
            ans2 = arr[high];
        }
        if (sum== 0) {
            cout << arr[low] << " "<< arr[high];
            return 0;
        }
        else if (sum > 0) {
            high -=1;
        }
        else {
            low += 1;
        }
    }
    cout<< ans1<< " "<< ans2;
}