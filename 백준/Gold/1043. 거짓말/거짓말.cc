#include <bits/stdc++.h>
using namespace std;
vector<int>party[52];
vector<int>route[52];
unordered_set<int>truth;
int cnt=0;
void go(int i) {
    for (auto j : party[i]) {
        if (truth.find(j)!=truth.end()) {
            return;
        }
    }
    cnt++;
}
void bfs(int z) {
    queue<int>q;
    q.push(z);
    int vis[52]={0};
    while (!q.empty()) {
        int top = q.front();
        truth.insert(top);

        q.pop();
        vis[top]=1;
        for (auto i : route[top]) {
            if (vis[i]==0) {
                q.push(i);
                vis[i]=1;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int N,M;
    cin>>N>>M;
    int num_of_truth;
    cin>>num_of_truth;
    int realoriginal=0;
    for(int i=0;i<num_of_truth;i++) {
        int k=0;
        cin>>k;
        if (i==0) {
            realoriginal=k;
        }
        else {
            route[realoriginal].push_back(k);
            route[k].push_back(realoriginal);
        }
        truth.insert(k);
    }
    for(int i=0;i<M;i++) {
        int p;
        cin>>p;
        int t;
        cin>>t;
        int original = t;
        party[i].push_back(t);
        for (int j=1;j<p;j++) {
            cin>>t;
            party[i].push_back(t);
            route[original].push_back(t);
            route[t].push_back(original);
        }
    }
    bfs(realoriginal);
    for (int i=0; i<M; i++) {
        go(i);
    }
    cout<<cnt;
}
