#include <bits/stdc++.h>
using namespace std;
vector<pair<long long int ,long long int >>v(1002);

vector<tuple<long long int ,long long int ,long long int >>dist;
vector<long long int > par(1002,-1);
double sum=0;
long long int  find(long long int  x) {
    if (par[x]<0)return x;
    return par[x] = find(par[x]);
}
void union_find(long long int  x, long long int  y) {
    x = find(x);
    y = find(y);
    if (x==y)return;
    if (par[x]>par[y]) {swap(x,y);}
    if (par[x]==par[y])par[x]--;
    par[y]=x;
}
 int  main() {
    long long int  N,M;
    cin>>N>>M;
    for(long long int  i=1;i<=N;i++) {
        cin >> v[i].first >> v[i].second;
    }
    for(long long int  i=1;i<=N; i++) {
        for(long long int  j=i+1;j<=N;j++) {
            long long int  x = v[i].first-v[j].first;
            long long int  y = v[i].second-v[j].second;
            dist.push_back({x*x+y*y,i,j});
        }
    }
    long long int  cnt=0;

    for (long long int  i=0; i<M; i++) {
        long long int  x,y;
        cin>>x>>y;
        if (find(x)==find(y)) {continue;}
        union_find(x,y);
        cnt++;
        if (cnt == N-1){ cout << fixed << setprecision(2) << round(sum * 100) / 100.0;return 0;}

    }

    sort(dist.begin(),dist.end());
    for (long long int  i=0; i<dist.size(); i++) {
        auto [weight,nod1,nod2] = dist[i];
        if (find(nod1)==find(nod2)) {continue;}
        union_find(nod1,nod2);
        sum+=sqrt(weight);
        cnt++;
        if (cnt == N-1){ cout << fixed << setprecision(2) << round(sum * 100) / 100.0;return 0;}
    }
    cout << fixed << setprecision(2) << round(sum * 100) / 100.0;

}