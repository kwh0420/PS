#include <bits/stdc++.h>
using namespace std;
int n, m;
vector <int> v;
int find(int x) {
    if (v[x]<0) return x;
    return v[x]  = find(v[x]);
}
int union_find(int x, int y) {
    x = find(x);
    y = find(y);
    if (x==y) return 1;
    if (v[x]>v[y]) swap(x, y);
    if (v[x]!=v[y]) v[x]--;
    v[y]=x;
    return 0;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    v.assign(n+1, -1);
    for (int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        if (union_find(a,b)) {cout << i+1;return 0;}
    }
    cout << 0;
}
