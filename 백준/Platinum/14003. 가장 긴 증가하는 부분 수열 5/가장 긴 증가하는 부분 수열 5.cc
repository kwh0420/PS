#include <bits/stdc++.h>
using namespace std;
long long int arr[1000002];
long long int pos[1000002];
long long int before[1000002];
long long int idx[1000002];
vector<int> v;
long long int n;
 int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (long long int i=0; i<n; i++) {
        cin >> arr[i];
        pos[i]=-1;
        before[i]=-1;
    }
    for (long long int i=0; i<n; i++) {
        auto it =lower_bound(v.begin(), v.end(), arr[i]);
        if (it == v.end()) {
            v.push_back(arr[i]);
            pos[i] = v.size()-1;
        }
        else {
            *it = arr[i];
            pos[i] = it - v.begin();

        }
        idx[pos[i]] = i;
        if (pos[i]-1>=0)
            before[i] =idx[pos[i]-1];
    }
    long long int k = idx[v.size()-1];
    vector<int> v;
    while (k>=0) {
        v.push_back(arr[k]);
        k=before[k];
    }
    reverse(v.begin(), v.end());
     cout << v.size() <<"\n";
    for (auto i : v) {
        cout << i << " ";
    }
}