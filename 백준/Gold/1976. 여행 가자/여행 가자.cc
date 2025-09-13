#include <bits/stdc++.h>
using namespace std;
int N,M;
vector<int> par(202,-1);
int find(int target) {
    if (par[target]<0) {
        return target;
    }
    return par[target]=find(par[target]);
}
int union_find(int a, int b) {
    a = find(a);
    b = find(b);
    if (a==b){return 0;}
    if (par[a]>par[b]) {swap(a,b);}
    if (par[a]==par[b])
    par[a]--;
    par[b]=a;
    return 1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            int test;
            cin >> test;
            if (test==1) {
                union_find(i,j);
            }
        }
    }
    int original;
    cin >> original;
    original=find(original);
    for (int i=2; i<=M; i++) {
        int k=0;
        cin>> k;
        if (original != find(k)){cout << "NO";return 0;}
    }
    cout << "YES";
}