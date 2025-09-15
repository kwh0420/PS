#include <bits/stdc++.h>
using namespace std;
vector<int> arr(1000003,-1);

int find(int target) {
    if (arr[target]<0)return target;
    return arr[target]= find(arr[target]);
}
void union_find(int u, int v) {
    u = find(u);
    v = find(v);
    if (u==v) return;
    if (arr[u]>arr[v]) {swap(u,v);}
    if (arr[u]==arr[v]) {
        arr[u]--;
    }
    arr[v]=u;
}
pair<int,int> v [5002];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int m;
    cin>>m;
    for (int i=0; i<m; i++) {
        int x,y;
        cin>>x>>y;
        v [i]={x,y};
    }
    sort(v , v +m);
    int cnt=0;
    int maxr=0;
    for (int i=0; i<m; i++) {
        auto [x,y] = v [i];
        for (int k=max(maxr,x); k<y; k++){union_find(k,k+1);};
        maxr=max(maxr,y);
    }
    for (int i=1; i<=n; i++) {
        if (arr[i]>0)continue;
        cnt++;
    }
    cout <<cnt;
}