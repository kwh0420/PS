#include <bits/stdc++.h>
using namespace std;
int N;
int arr1[1002];
int arr2[51];
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr1[i];
    }
    sort(arr1, arr1 + N);
    int sum=0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            sum+=arr1[j];
        }
    }
    cout << sum;
}