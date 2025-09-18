#include <bits/stdc++.h>
using namespace std;
vector<long long int > par(1002,-1);
vector<tuple<long long int ,long long int ,long long int >> t;
vector<tuple<long long int ,long long int ,long long int >> t2;

int nxt[1002];
int cost[1002];
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

    long long int  n,m,n1=0,n2=0;
    cin>> n>>m;
    int trash,trash2,c;
    cin>>trash >> trash2 >> c;
    if (c==0){n1++; n2++;}
    for (int i=1; i<m+1; i++) {
        long long int w,u,v;
        cin>>w>>u>>v;
        if (v==0) v= 1;
        else v=-1;
        t.push_back(make_tuple(v,w,u));
        t2.push_back ({v,w,u});
    }
    sort(t.begin(),t.end());
    sort (t2.begin(),t2.end(),greater<tuple<long long int ,long long int,long long int >>());
    long long int  cnt=0;
    for (auto i : t) {
        auto [weight,node1,node2] = i;
        if (find(node1)== find(node2)) {continue;}
        union_find(node1,node2);
        //cout << weight <<" " << node1 << " " <<node2 << endl;
        if (weight == 1) n1++;
        cnt++;
        int maxval = max(node1,node2);
        int minval = min(node1,node2);
        nxt[minval]=maxval;
        cost[minval]= weight;
        if (cnt==n-1)break;
    }

    cnt=0;
    par.assign(1002,-1);
    for (int i=0; i<1002; i++) {
        nxt[i]=0;
        cost[i]=0;
    }
    for (auto i : t2) {
        auto [weight,node1,node2] = i;
        if (find(node1)== find(node2)) {continue;}
        union_find(node1,node2);
        //cout << weight <<" " << node1 << " " <<node2 << endl;
        cnt++;
        if (weight == 1){n2++;}
        long long int maxval = max(node1,node2);
        long long int minval = min(node1,node2);
        nxt[minval]=maxval;
        cost[minval]= weight;
        if (cnt==n-1)break;
    }
    if (n1<0)n1=0;
    if (n2<0)n2=0;
    cout << n2*n2 - n1*n1;
}