#include <bits/stdc++.h>
using namespace std;
vector<int>ve[1002];
int visita[1002];
int cnt=0;
void bfs(int k) {
    queue<pair<int,int>>q;
    q.push({k,0});
    visita[k] = 1;
    while (!q.empty()) {
        auto[cur,depth] = q.front();
        visita[cur] = 1;
        q.pop();

        if (depth==2) {
            continue;
        }
        for (auto i : ve[cur]) {
            if (!visita[i]) {
                cnt++;
                q.push({i,depth+1});
                visita[i] = 1;
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u,v;
        cin >> u >> v;
        ve[u].push_back(v);
        ve[v].push_back(u);
    }
    for (int i = 0; i <= N; i++) {
        sort(ve[i].begin(), ve[i].end());
    }
    bfs(1);
    cout << cnt;
}
