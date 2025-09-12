#include <bits/stdc++.h>
using namespace std;
int depthmin[10002];
int depthmax[10002];
int location[10002];
int lc[10002];
int rc[10002];
int cnt=0;
int par[10002];
void dfs(int i,int d) {
    int l = lc[i];
    int r = rc[i];

    if (l!=-1) dfs(l,d+1);
    location[i]=++cnt;
    depthmin[d]=min(depthmin[d],location[i]);
    depthmax[d]=max(depthmax[d],location[i]);
    if (r!=-1) dfs(r,d+1);
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        lc[a]=b;
        rc[a]=c;
        if (b!=-1)par[b]=a;
        if (c!=-1)par[c]=a;
        depthmin[i+1]=1e9;
    }
    int root=0;
    for (int i = 1; i <= n; i++) {
        if (par[i]==0)root=i;
    }
    dfs(root,1);
    int maxlevel=1;
    int maxval=0;
    for (int i = 1; i <=n; i++) {
        if (maxval<depthmax[i]-depthmin[i]) {maxval=depthmax[i]-depthmin[i];maxlevel=i;}
    }
    cout << maxlevel <<" " << maxval+1;
}