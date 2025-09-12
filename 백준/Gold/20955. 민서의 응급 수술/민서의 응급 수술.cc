#include <bits/stdc++.h>
using namespace std;
vector<int> v[100002];
int vis[100002];
int par[100002];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M;
    cin>>N>>M;
    for(int i=0;i<M;i++) {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int ans=0;
    int cnt=0;
    int result=0;
    for(int i=1;i<=N;i++) {
        if (vis[i] == 1){continue;}
        cnt++;
        queue<int> q;
        q.push(i);
        vis[i] = 1;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            for(int j=0;j<v[cur].size();j++) {
                if(vis[v[cur][j]] == 1) {
                    if (v[cur][j]!=par[cur]) // 사이클 = (다시 방문한 정점 중 부모노드가 아닌 정점의 개수)/2
                    {ans++;}
                }
                else{
                    q.push(v[cur][j]);
                    vis[v[cur][j]] = 1;
                    par[v[cur][j]] = cur;
                }
            }
        }
    }cout<<(ans/2)+cnt-1;

}

