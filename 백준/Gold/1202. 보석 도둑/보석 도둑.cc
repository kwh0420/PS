#include <bits/stdc++.h>
using namespace std;
long long int n,k;
multiset<long long int> s;
long long int sum=0;
priority_queue<pair<long long int,long long int> > pq;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    for(long long int i=0; i<n; i++) {
        long long int q,r;
        cin>>q >>r;
        pq.push(make_pair(r,q));
    }
    for (long long int i=0; i<k;i++) {
        long long int g;
        cin>>g;
        s.insert(g);
    }
    while (!pq.empty()) {
        auto[v,w]  =pq.top();
        pq.pop();
        auto it = s.lower_bound(w);
        if (s.end()!=it) {
            sum+=v;
            s.erase(it);
        };
    }
    cout << sum;

}