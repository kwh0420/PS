#include <bits/stdc++.h>
using namespace std;
vector<long long int > par(1002,-1);
vector<tuple<long long int ,long long int ,long long int >> t;
long long int  sum=0;
long long int  find(long long int  target) {
    if (par[target]<0) return target;
    return par[target] = find(par[target]);
}
long long int  union_find(long long int  v, long long int  w) {
    v=find(v);
    w=find(w);
    if (v==w)return 0;
    if (par[v]>par[w]) {swap(v,w);}
    if (par[v]==par[w]) {par[v]--;}
    par[w]=v;
    return 1;
}
int  main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long int  n;
    cin>> n;
    for(long long int  i=0;i<n;i++) {
        for(long long int  j=0;j<n;j++) {
            long long int  v;
            cin>>v;
            t.emplace_back(v,i,j);
        }
    }
    sort(t.begin(),t.end());
    long long int  cnt=0;
    for (auto i : t) {
        auto [weight,node1,node2] = i;
        if (union_find(node1,node2)){sum+=weight;}
        else {continue;}
        cnt++;
        if (cnt==n-1)break;
    }
    cout << sum;
}