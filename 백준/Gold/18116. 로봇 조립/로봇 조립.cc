#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> v(1e6+1,-1);
int find(int x) {
    if (v[x]<0) return x;
    return v[x] = find(v[x]);
}
int union_find(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return 0;
    if (v[x]>v[y]) swap(x,y);
    v[x]+= v[y];
    v[y]=x;
    return 1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        char command;
        cin >> command;
        if (command =='I') {
            int a,b;
            cin >> a >> b;
            union_find(a,b);
        }
        else {
            int a;
            cin >> a;
            cout << -v[find(a)]<<"\n";
        }
    }
}