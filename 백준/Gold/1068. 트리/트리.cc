#include <bits/stdc++.h>
using namespace std;
int par[100000];
vector<int> v[100000];
int n;
int dfs(int cur,int par) {
    if (v[cur].size()==1 ) {return 1;}
    int result=0;
    for (auto i : v[cur]) {
        if (i == par) {
            continue;
        }
        result+=dfs(i,cur);
    }
    return result;
}
int main() {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        par[i]=a;
        v[i].push_back(a);
        if (a!=-1)
        v[a].push_back(i);
    }
    int k;
    cin >> k;
    int p = par[k];
    if (p==-1) { cout << 0 ; return 0;}
    v[p].erase(remove(v[p].begin(), v[p].end(), k), v[p].end());
    int st=0;
    for (int i=0; i<n; i++) {
        if (par[i]==-1){st=i;}
    }
    cout << dfs(st,-1);
}