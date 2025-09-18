#include <bits/stdc++.h>
using namespace std;
vector<pair<long long int,long long int>> v[100002];
priority_queue<tuple<long long int,long long int,long long int>, vector<tuple<long long int,long long int,long long int>>, greater<tuple<long long int,long long int,long long int>>> t;
long long int chk[100002];
multiset<long long int> w;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long int N,M;
    cin>>N>>M;
    for (long long int i=0;i<M; i++) {
        long long int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({c,b});
        v[b].push_back({c,a});
    }
    for (auto i : v[1]) {
        t.push({i.first,1,i.second});
    }
    chk[1]=1;
    long long int cnt=0;
    long long int sum=0;

    while (cnt<N-1) {
        auto [cur_weight, cur_u, cur_v] = t.top();
        t.pop();
        if (chk[cur_v])continue;
        chk[cur_v] = 1;
        cnt++;
        w.insert(cur_weight);
        for (auto i : v[cur_v]) {
            if (chk[i.second]) {continue;}
            t.push({i.first,cur_v,i.second});
        }
    }
    w.erase(prev(w.end()));
    for (auto i : w) {
        sum+=i;
    }
    cout<<sum;
}