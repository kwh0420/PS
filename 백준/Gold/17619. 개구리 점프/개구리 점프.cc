#include <bits/stdc++.h>
using namespace std;
int N,M;
vector<int> par(1e5+2,-1);
map<tuple<int,int,int>,int>mp;
set<tuple<int,int,int>>st;
int find(int target) {
    if (par[target]<0) return target;
    return par[target] = find(par[target]);
}
int union_find(int u, int v) {
    u=find(u);
    v=find(v);
    if (u==v)return 0;
    if (par[u]>par[v]) swap(u, v);
    if (par[u]==par[v]) par[u]--;
    par[v]=u;
    return 1;
}
int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        auto it =st.lower_bound({a,b,c});
        if (st.size()>0&&it==st.end()){it--;}
        mp[{b,a,c}]=i;
        int y = get<0>((*it));
        int x = get<1>((*it));
        if (y>=a&& x<=b) {
            int num = mp[*it];
            union_find(num,i);
        }
        st.insert({b,a,c});
    }
    for (int i=1; i<=M; i++) {
        int a,b;
        cin >> a >> b;
        if (find(a) == find (b)){cout << "1\n";}
        else {cout <<"0\n";}
    }
}