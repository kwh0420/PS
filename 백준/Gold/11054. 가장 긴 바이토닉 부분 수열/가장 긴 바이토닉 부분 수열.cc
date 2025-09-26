#include <bits/stdc++.h>
using namespace std;
int arr[1002];
int increase[1002];
int decrease[1002];
vector<int> increasing;
vector<int> decreasing;
int N;
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < N; i++) {
        auto it = lower_bound(increasing.begin(), increasing.end(), arr[i]);
        int idx = it - increasing.begin();
        if (it == increasing.end()) {increasing.push_back(arr[i]);}
        else {increasing[idx]=arr[i];}
        increase[i]=idx+1;
    }
    for (int i = N-1;i>=0; i--) {
        auto it = lower_bound(decreasing.begin(), decreasing.end(), arr[i]);
        int idx = it - decreasing.begin();
        if (it == decreasing.end()) {decreasing.push_back(arr[i]);}
        else {decreasing[idx]=arr[i];}
        decrease[i]=idx+1;
    }
    int maxval=0;
    for (int i = 0; i < N; i++) {
        maxval = max(maxval, increase[i] + decrease[i] - 1);
    }
    cout << maxval;

}