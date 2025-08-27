#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> di[20001];
int dist[20001];
void go (int n) {
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push(make_pair(0,n));
    dist[n] = 0;
    while (!q.empty()) {
        pair<int,int> p = q.top();
        q.pop();
        int cur = p.second;
        int val = p.first;
        if (dist[cur] != val) {
            continue;
        }
        for (auto i : di[cur]) {
            int ncur = i.second;
            int nval = dist[cur] + i.first;
            if (dist[ncur] <= nval) { continue;}
            dist[ncur]=nval;
            q.push({nval,ncur});
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int V,E;
    cin >> V >> E;
    int k;
    cin>>k;
    for (int i=1; i<=V; i++) {
        dist[i]=1e9+10;
    }
    for(int i=0;i<E;i++) {
        int u,v,w;
        cin >> u >> v >>w;
        di[u].push_back({w,v});
    }
    go(k);
    for (int i=1; i<=V; i++) {
        if (dist[i] == 1e9+10) {cout << "INF\n";}
        else cout << dist[i] << "\n";
    }
}