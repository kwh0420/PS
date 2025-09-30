#include <bits/stdc++.h>
using namespace std;
long long int n;
long long int arr[100003];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (long long int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    long long int pointer1 =0;long long int pointer2 =n-1;
    long long int maxval=1e18;
    long long int val1=0;
    long long int val2=0;
    while (pointer1 < pointer2) {
        long long int k = arr[pointer1] + arr[pointer2];
        if (abs(k)<maxval) {
            val1 = arr[pointer1];
            val2 = arr[pointer2];
            maxval = abs(k);
        }
        if (k>0) {pointer2--;}
        else if (k ==0) {break;}
        else { pointer1++;}
    }
    cout << val1 << " " << val2;
}