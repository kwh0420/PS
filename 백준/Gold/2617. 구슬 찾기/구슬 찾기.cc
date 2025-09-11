#include <bits/stdc++.h>
using namespace std;

int num[102][2];       // [i][0] = i보다 큰 구슬 수, [i][1] = i보다 작은 구슬 수
vector<int> v1[102];   // i보다 큰 구슬 그래프
vector<int> v2[102];   // i보다 작은 구슬 그래프
set<pair<int,int>> ss;

int dfs1(int i, vector<int>& vis) {
    vis[i] = 1;
    int cnt = 0;
    for (auto j : v1[i]) {
        if (!vis[j]) cnt += dfs1(j, vis) + 1;
    }
    return cnt;
}

int dfs2(int i, vector<int>& vis) {
    vis[i] = 1;
    int cnt = 0;
    for (auto j : v2[i]) {
        if (!vis[j]) cnt += dfs2(j, vis) + 1;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        if (ss.count({a,b})) continue;  // 중복 간선 방지
        v1[a].push_back(b);  // a보다 큰 b
        v2[b].push_back(a);  // b보다 작은 a
        ss.insert({a,b});
    }

    for (int i=1; i<=n; i++) {
        vector<int> vis1(n+1, 0);
        num[i][0] = dfs1(i, vis1);

        vector<int> vis2(n+1, 0);
        num[i][1] = dfs2(i, vis2);
    }

    int limit = (n-1)/2;
    int cnt = 0;
    for (int i=1; i<=n; i++) {
        if (num[i][0] > limit || num[i][1] > limit) cnt++;
    }
    cout << cnt;
}