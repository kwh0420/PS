#include <bits/stdc++.h>
using namespace std;
int par[100002];
vector<int> v[100002];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto nxt : v[cur]) {
            if (par[cur]==nxt)continue;
            par[nxt] = cur;
            q.push(nxt);
        }
    }
    for (int i=2; i<=n; i++) {
        cout << par[i] << "\n";
    }
}
