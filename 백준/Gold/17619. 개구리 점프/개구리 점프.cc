#include <bits/stdc++.h>
using namespace std;
long long int N,M;
vector<long long int> par(1e6+2,-1);
map<tuple<long long int,long long int,long long int>,long long int>mp;
set<tuple<long long int,long long int,long long int>>st;
long long int find(long long int target) {
    if (par[target]<0) return target;
    return par[target] = find(par[target]);
}
long long int union_find(long long int u, long long int v) {
    u=find(u);
    v=find(v);
    if (u==v)return 0;
    if (par[u]>par[v]) swap(u, v);
    if (par[u]==par[v]) par[u]--;
    par[v]=u;
    return 1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (long long int i = 1; i <= N; i++) {
        long long int a,b,c;
        cin >> a >> b >> c;
        mp[{a,b,c}]=i;
        st.insert({a,b,c});
    }
    long long int cnt=1;
    auto it = st.begin();
    long long int maxr=get<1>(*st.begin());
    auto [x,y,z]=*it;
    long int maxidx=mp[{x,y,z}];
    for (auto it = st.begin() ; it != st.end() ; it++){
        long long int x=get<0>(*it);
        long long int y=get<1>(*it);
        long long int z= get<2>(*it);

        long long int idx1= mp[{x,y,z}];
        cnt++;
        if (x<=maxr){union_find(idx1,maxidx);}
        if (maxr<y) {
            maxr=y;
            maxidx=idx1;
        }
        cnt++;
    }
    for (long long int i=1; i<=M; i++) {
        long long int a,b;
        cin >> a >> b;
        if (find(a) == find (b)){cout << "1\n";}
        else {cout <<"0\n";}
    }
}