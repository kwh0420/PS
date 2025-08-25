#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> v;
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a=0;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    int maxval=0;
    for (int i = 0; i < N; i++) {
        maxval = max(maxval, v[i]*(N-i));
    }
    cout << maxval;
}