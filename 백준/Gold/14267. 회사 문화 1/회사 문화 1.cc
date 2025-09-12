#include <bits/stdc++.h>
using namespace std;
vector<int> v[100002];
int par[100002];
int result[100002];
void dfs(int cur, int par) {
    for (auto i : v[cur]) {
        if (i == par) {continue;}
        result[i]+=result[cur];
    }
}
int main() {
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++) {
        int a;
        cin>>a;
        if (a==-1){continue;}
        v[i].push_back(a);
        v[a].push_back(i);
        par[i]=a;
    }
    for(int i=1; i<=m; i++) {
        int a,b;
        cin>>a>>b;
        result[a]+=b;
    }
    queue<int> q;
    q.push(1);
    while (!q.empty()) { // 한번에 전파하면 O(N+M), M들어올때마다 전파하면 O(NM).. 설계 잘해야함. 그리고 N=100000이라 재귀로는 못푸니 주의
        int cur=q.front();
        q.pop();
        for (auto i : v[cur]) {
            if (i==par[cur])continue;
            result[i]+=result[cur];
            q.push(i);
        }
    }
    for(int i=1; i<=n; i++) {
        cout<<result[i]<<" ";
    }

}
