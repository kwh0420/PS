#include <bits/stdc++.h>
using namespace std;
int arr[1002];
vector<int> sum;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    int idx = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            sum.push_back( arr[i] + arr[j]);
        }
    }
    sort(sum.begin(), sum.end());
    int maxval = 0;
    for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (binary_search(sum.begin(), sum.end(), arr[i]-arr[j])) {
                cout << arr[i];
                return 0;
            }
        }
    }
    cout << maxval;
}
