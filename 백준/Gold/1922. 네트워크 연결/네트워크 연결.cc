#include <bits/stdc++.h>
using namespace std;
long long int  par[1002];
vector<pair<long long int ,long long int >> v[1002];
#define tt tuple<long long int ,long long int ,long long int >
priority_queue<tt,vector<tt>,greater<tt>> q;
long long int  find(long long int  target) {
    if (par[target]<0) return target;
    return par[target] = find(par[target]);
}
long long int  union_find(long long int  a, long long int  b) {
    a = find(a);
    b = find(b);
    if (a==b) { return 0;}
    if (par[a]>par[b]) {swap(a, b);}
    if (par[a]==par[b]) {par[a]--;}
    par[b] = a;
    return 1;
}
int  main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long int  n;
    cin >> n;
    for (long long int  i=0; i<n; i++) {
        par[i]=-1;
    }
    long long int  m;
    cin >> m;
    for (long long int  i=0; i<m; i++) {
        long long int  a,b,c;
        cin >> a >> b >> c;
        q.push(make_tuple(c,a,b));
    }
    long long int  cnt=0;
    long long int  result=0;
    while (cnt<n-1) {
        auto [weight, node1, node2]= q.top();
        q.pop();
        if (find(node1)==find(node2)) {continue;}
        union_find(node1, node2);
        result+=weight;
        cnt++;
    }
    cout << result;

}