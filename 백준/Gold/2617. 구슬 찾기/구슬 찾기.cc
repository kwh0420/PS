#include <bits/stdc++.h>
using namespace std;
int num[102][2];
vector<int> v1[102];
vector<int> v2[102];
set<pair<int,int>>ss;
void bfs1(int i) {
    int vis[102]={0};
    queue<int> q;
    q.push(i);
    vis[i]=1;
    int cnt=0;
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        for (auto j : v1[u]) {
            if(vis[j]==0) {
                cnt++;
                q.push(j);
                vis[j]=1;
            }
        }
    }
    num[i][0]=cnt;
}
void bfs2(int i) {
    int vis[102]={0};
    queue<int> q;
    q.push(i);
    vis[i]=1;
    int cnt=0;
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        for (auto j : v2[u]) {
            if(vis[j]==0) {
                cnt++;
                q.push(j);
                vis[j]=1;
            }
        }
    }
    num[i][1]=cnt;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++) {
        num[i][0]=-1;
        num[i][1]=-1;
    }
    for(int i=0;i<m;i++) {
        int a,b;
        cin>>a>>b;
        if (ss.find({a,b})!=ss.end()) continue;
        v1[a].push_back(b);
        v2[b].push_back(a);
        ss.insert({a,b});
    }
    for (int i=1; i<=n; i++) {
        bfs1(i);
        bfs2(i);
    }
    int limit = (n-1)/2;
    int cnt=0;
    for(int i=1;i<=n;i++) {
        if (limit < num[i][0] || limit < num[i][1]) {
            cnt++;
        }
    }
    cout << cnt;
}

