#include <bits/stdc++.h>
using namespace std;
int vis[100002];
int par[100002];
vector<int> v[100002];
int bfs(int k) {
    if (vis[k])return 0;
    queue<int> q;
    q.push(k);
    vis[k] = 1;
    int notree=1;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto nxt : v[cur]) {
            if (par[cur]==nxt){continue;}
            if (vis[nxt] == 1) {notree=0;}
            else {
                vis[nxt] = 1;
                par[nxt] = cur;
                q.push(nxt);
            }
        }
    }
    return notree;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int casenum=0;
    while (1) {
        casenum++;
        int n,m;
        cin>>n>>m;
        if (n==0 && m==0) {break;}
        for(int i=0;i<m;i++) {
            int q,w;
            cin>>q>>w;
            v[q].push_back(w);
            v[w].push_back(q);
        }
        int cnt=0;
        for(int i=1;i<=n;i++) {
            cnt+=bfs(i);
        }
        if (cnt==0) {
            cout << "Case "<<casenum<<": No trees.\n";
        }
        else if (cnt==1) {
            cout << "Case "<<casenum<<": There is one tree.\n";
        }
        else {
            cout << "Case "<<casenum<<": A forest of "<<cnt<<" trees.\n";
        }
        for(int i=1;i<=n;i++) {
            vis[i]=0;
            v[i].clear();
            par[i]=0;
        }
    }
}
