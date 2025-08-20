#include <bits/stdc++.h>
using namespace std;
int n;
int a[10005];
int dp1[10005];
int dp2[10005];
vector<int> v[10005];
void tree_bfs(int cur,int par) {
    dp1[cur] = a[cur];
    dp2[cur]=0;
    for (int i : v[cur]) {
        if (par==i)continue;
        tree_bfs(i,cur);
        dp1[cur] +=dp2[i];
        dp2[cur]+=max(dp1[i],dp2[i]);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for (int i=1; i<=n; i++) {
        cin>>a[i];
    }
    for (int i=0; i<n-1; i++) {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    tree_bfs(1,0);
    cout << max(dp1[1],dp2[1]);
}