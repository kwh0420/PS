#include <bits/stdc++.h>
using namespace std;
vector<int>ve[20002];
int visita[20002];
int cnt=0;
int bfs(int k) {
    queue<int>q;
    q.push(k);
    visita[k] = 1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto i : ve[cur]) {
            if (!visita[i]) {
                q.push({i});
                visita[i] = visita[cur]*(-1);
            }
            else if (visita[i]==visita[cur]) {
                return 0;
            }

        }
    }
    return 1;
}
void go(){
    int N, M;
    cin >> N >> M;
    cnt=0;
    for (int i=1; i<=N; i++) {
        ve[i].clear();
        visita[i] = 0;
    }
    for (int i = 0; i < M; i++) {
        int u,v;
        cin >> u >> v;
        ve[u].push_back(v);
        ve[v].push_back(u);
    }
    for (int i=1; i<=N; i++) {
        if (!visita[i]) {
            if (!bfs(i)) {
                cout << "NO" << "\n";
                return;
            };
        }
    }
    cout << "YES\n";

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int T;
    cin>>T;
    for(int i=1;i<=T;i++) {
        go();
    }
}
