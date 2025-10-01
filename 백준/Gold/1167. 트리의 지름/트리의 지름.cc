#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v[100002];
long long int N;
long long int ans=0;
long long int visited[100002];
long long int dfs(long long int cur,long long int par) {
    if (v[cur].size()==1 && cur!=par){return 0;}
    priority_queue<int> pq;
    for (auto [nxt_node,weight] : v[cur]) {
        if (visited[nxt_node] || cur == nxt_node) continue;
        visited[nxt_node]=1;
        long long int k=dfs(nxt_node,cur)+weight;
        pq.push(k);
    }
    long long int maxval1=0,maxval2=0;
    if (!pq.empty()) {maxval1=pq.top();pq.pop();}
    if (!pq.empty()) {maxval2=pq.top();pq.pop();}
    ans = max(ans,maxval1+maxval2);
    return maxval1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (long long int i=0;i<N;i++) {
        long long int a;
        cin >> a;
        while (1) {
            long long int b,c;
            cin >> b;
            if (b==-1){break;}
            cin >> c;
            v[a].push_back({b,c});
            v[b].push_back({a,c});
        }
    }
    visited[1]=1;
    dfs(1,-1);
    cout << ans;
}