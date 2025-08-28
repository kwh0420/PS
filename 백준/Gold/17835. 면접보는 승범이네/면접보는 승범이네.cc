#include <bits/stdc++.h>
using namespace std;
vector<pair<long long int,long long int>> v[100002];
long long int dist[100002];
long long int dest[100002];
long long int result_max_val;
long long int result_max_node;
long long int result[100002];
long long int N,M,K;
void go() {
    for (long long int i=1; i<=N; i++) {
        dist[i]=1e18;
    }
    priority_queue<pair<long long int,long long int>,vector<pair<long long int,long long int>>,greater<pair<long long int,long long int>>> q;
    for (int i = 0; i < K; i++) {
        dist[dest[i]] = 0;
        q.push({0, dest[i]});
    }
    while (!q.empty()) {
        pair<long long int,long long int> p = q.top();
        q.pop();
        long long int cur_idx = p.second;
        long long int cur_weight = p.first;
        if (dist[cur_idx] != p.first) {
            continue;
        }
        for (auto i : v[cur_idx]) {
            long long int next_idx = i.second;
            long long int next_weight = i.first + cur_weight;
            if (dist[next_idx]<=next_weight){continue;}
            dist[next_idx] = next_weight;
            q.push({next_weight,next_idx});
        }
    }

    for (long long int i=1; i<=N; i++) {
            result[i]=dist[i];
    }

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M>>K;
    for (long long int i=0; i<M; i++) {
        long long int U,V,C;
        cin>>U>>V>>C;
        v[V].push_back(make_pair(C,U));
    }

    for (int i=0; i<K; i++) {
        cin>>dest[i];
    }
    priority_queue<long long int>q;
    go();
    result_max_val=result[1];
    result_max_node=1;
    for (long long int i=2; i<=N; i++) {
        if (result[i]>result_max_val) {
            result_max_val = result[i];
            result_max_node = i;
        }
    }

    cout << result_max_node<< "\n";
    cout << result_max_val << "\n";

}