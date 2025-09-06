#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> m;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            string clothes, type;
            cin >> clothes >> type;
            m[type]++;
        }
        int cnt = 1;
        for (auto i: m) {
            cnt *= i.second+1;
        }
        cout << cnt-1 << '\n';
        m.clear();
    }
}
