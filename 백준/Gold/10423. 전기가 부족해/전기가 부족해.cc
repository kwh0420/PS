#include <bits/stdc++.h>
using namespace std;
int N,M,K;
#define ll long long int
vector<pair<ll,ll>>v[1002];
ll vis[1002];
ll cnt=0;

priority_queue<tuple<ll,ll,ll>,vector<tuple<ll,ll,ll>>,greater<tuple<ll,ll,ll>>>pq;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> K;
    for (int i = 1; i <= K; i++) {
        int u;
        cin >> u;
        pq.push({0,0,u});
    }
    for (int i=1 ; i<=M; i++) {
        int u,a,w;
        cin >> u >> a >> w;
        v[u].push_back({w,a});
        v[a].push_back({w,u});
    }
    ll sum=0;
    while (!pq.empty()) {
        auto [weight,node1,node2] = pq.top();
        pq.pop();
        if (vis[node2]) continue;

        vis[node2]=1;
        cnt++;
        sum+=weight;
        if (cnt == N )break;
        for (auto i : v[node2]) {
            auto [next_weight,next_node]= i;
            //cout << next_weight << " " << node2 << " " << next_node << endl;
            pq.push({next_weight,node2,next_node});
        }
    }
    cout << sum;
}