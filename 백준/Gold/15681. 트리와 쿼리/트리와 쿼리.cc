#include <bits/stdc++.h>
using namespace std;
int result[100002];
vector<int> v[100002];
int dfs(int cur,int par){
    int sumofsubtrees = 1;
    for (auto i : v[cur]) {
        if (i==par){continue;}
        sumofsubtrees += dfs(i,cur);
    }
    return result[cur]=sumofsubtrees;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,R,Q;
    cin>>N>>R>>Q;
    for (int i=1;i<=N-1; i++) {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
        dfs(R,-1);

    for (int i=0; i<Q;i++) {
        int t;
        cin>>t;
        cout << result[t]<<"\n";
    }
}
