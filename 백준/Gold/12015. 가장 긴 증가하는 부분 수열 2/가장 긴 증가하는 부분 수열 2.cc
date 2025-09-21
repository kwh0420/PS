#include <bits/stdc++.h>
using namespace std;
int N;
vector<int>v;
int dp[1000002];
set<int>s;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a ;
        v.push_back(a);
    }
    for (int i = 0; i < N; i++) {
        if (s.lower_bound(v[i]) == s.end()) {s.insert(v[i]);}
        else {auto it = s.lower_bound(v[i]);(s.erase(it));s.insert(v[i]);}
    }
    cout << s.size();
}