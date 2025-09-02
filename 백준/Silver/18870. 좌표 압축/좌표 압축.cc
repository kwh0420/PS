#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
   vector<int> v;
    int arr[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        v.push_back(arr[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < N; i++) {
        cout<<lower_bound(v.begin(), v.end(), arr[i])-v.begin()<<" ";
    }
}