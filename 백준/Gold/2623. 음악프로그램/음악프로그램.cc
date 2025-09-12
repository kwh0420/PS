#include <bits/stdc++.h>
using namespace std;
int indegree[32001];
vector<int> v[32001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N,M;
    cin>>N>>M;
    for(int i=0;i<M;i++) {
        int K;
        cin>>K;
        int a;
        cin >> a;
        for(int j=1;j<K;j++) {
            int b;
            cin >> b;
            v[a].push_back(b);
            indegree[b]++;
            a=b;
        }
    }
    queue<int> q;
    for(int i=1;i<=N;i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }
    vector<int> result;
    while(!q.empty()) {
        int t=q.front();
        q.pop();
        result.push_back(t);
        for (auto i : v[t]) {
            indegree[i]--;
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
    }
    if (result.size() == N) {
        for ( auto i : result ) {
            cout<<i<<"\n";
        }
    }
    else {
        cout << 0;
    }
}