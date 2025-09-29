#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> v[200002];
int maxval=0;
int dfs(int cur,int par) {
    priority_queue<int> pq;
    if (v[cur].size()==1 && cur != 1){return 0;}
    for (auto i : v[cur]) {
        if (i.first == par) {
            continue;
        }
        pq.push(dfs(i.first,cur)+i.second);
    }
    int n1=0;
    if (!pq.empty()) n1=pq.top();
    if (!pq.empty())pq.pop();
    int n2=0;
    if (!pq.empty()) {n2+=pq.top();}
    maxval = max(maxval,n1+n2);
    return n1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    for(int i=0;i<n-1;i++) {
        int par,child,weight;
        cin>>par>>child>>weight;
        v[par].push_back(make_pair(child,weight));
        v[child].push_back(make_pair(par,weight));

    }
    dfs(1,-1);
    cout << maxval;
}