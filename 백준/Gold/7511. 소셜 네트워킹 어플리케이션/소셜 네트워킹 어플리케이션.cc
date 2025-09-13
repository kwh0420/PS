#include <bits/stdc++.h>
using namespace std;
vector<int> v(1e6,-1);
int find(int i) {
    if (v[i]<0) return i;
    return v[i] = find(v[i]);
}
int union1(int u, int x) {
    u=find(u);
    x=find(x);
    if (u==x) return 0;
    if (v[u]>v[x]){swap(u,x);}
    v[u]--;
    v[x]=u;
    return u;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    for (int i=0; i<t; i++) {
        int n;
        cin>>n;
        v.assign(n+1,-1);
        int k;
        cin>>k;
        for (int i=0; i<k; i++) {
            int q,w;
            cin>>q>>w;
            union1(q,w);
        }
        int p;
        cin>>p;
        cout << "Scenario "<<i+1<<":\n";
        for (int i=0; i<p; i++) {
            int a,b;
            cin>>a>>b;
            if (find(a)!=find(b)) {
                cout << "0\n";
            }
            else {
                cout << "1\n";
            }
        }
        cout <<"\n";
    }
}