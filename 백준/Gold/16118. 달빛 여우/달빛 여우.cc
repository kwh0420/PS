#include <bits/stdc++.h>
using namespace std;
long long int N, M;
vector<pair<long long int, long long int> > v[4002];
vector<long long int> dist1(4002,1e18);
vector<long long int> dist2holsu(4002,1e18);
vector<long long int> dist2zzaksu(4002,1e18);
vector<long long int> dist2(4002,1e18);

void di1(long long int start) {
    dist1[start] = 0;
    priority_queue<pair<long long int, long long int>,vector<pair<long long int,long long int>>,greater<pair<long long int,long long int>>> pq;
    pq.push(make_pair(0,start));
    while(!pq.empty()) {
        auto[cur_weight,cur_node] = pq.top();
        pq.pop();
        if (dist1[cur_node]!=cur_weight)continue;
        for (auto [ncur_weight,ncur_node] : v[cur_node]) {
            long long int ndist = cur_weight + ncur_weight;
            if (dist1[ncur_node] > ndist) {
                dist1[ncur_node] = ndist;
                pq.push(make_pair(ndist,ncur_node));
            }
        }
    }
}
void di2(long long int start) {
    dist2zzaksu[start] = 0;
    priority_queue<tuple<long long int,long long int,long long int>,vector<tuple<long long int,long long int,long long int>>,greater<tuple<long long int,long long int,long long int>>> pq;
    pq.push({0,start,0});
    while(!pq.empty()) {
        auto[cur_weight,cur_node,cur_cnt] = pq.top();
        pq.pop();
        if (cur_cnt%2==1){if (dist2holsu[cur_node]<cur_weight) {continue;}}
        if (cur_cnt%2==0){if (dist2zzaksu[cur_node]<cur_weight){continue;}}
        for (auto [ncur_weight,ncur_node] : v[cur_node]) {
            long long int ndist;
            if (cur_cnt%2==0){ndist= cur_weight + (ncur_weight)/2;}
            else {ndist= cur_weight + (ncur_weight)*2;}
                if (cur_cnt%2 ==1) {
                    if (dist2zzaksu[ncur_node] > ndist) {
                        dist2zzaksu[ncur_node] = ndist;
                        pq.push({ndist,ncur_node,cur_cnt+1});
                    }
                }
                else {
                    if (dist2holsu[ncur_node] > ndist) {
                        dist2holsu[ncur_node] = ndist;
                        pq.push({ndist,ncur_node,cur_cnt+1});
                    }
                }
            }
        }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (long long int i = 0; i < M; i++) {
        long long int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back(make_pair(c*2,b));
        v[b].push_back(make_pair(c*2,a));

    }

    di1(1);
    di2(1);
    long long int cnt=0;
    for (long long int i=2 ;i <=N; i++) {
       dist2[i] = min (dist2zzaksu[i],dist2holsu[i]);
    }
    for (long long int i=2 ;i <=N; i++) {
        if (dist1[i]<dist2[i]) {cnt++;}
    }
    cout << cnt;
}
