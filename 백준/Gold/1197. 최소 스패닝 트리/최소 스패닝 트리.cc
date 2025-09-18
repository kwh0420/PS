#include <bits/stdc++.h>
using namespace std;
vector<int> par(10002,-1);
int weight[10002];
vector<tuple<int,int,int>> t;
int find(int target) {
    if (par[target]<0)return target;
    return par[target] = find(par[target]);
}
void union_find(int a, int b,int w) {
    a = find(a);
    b = find(b);
    if (a==b)return;
    if (par[a]>par[b]) {swap(a, b);}
    if (par[a]==par[b]) par[a]--;
    par[b] = a;
    weight[a] += weight[b]+w;

}
int main() {
    int n,m;
    cin>>n>>m;
    for (int i=0;i<m;i++) {
        int A,B,C;
        cin>>A>>B>>C;
        t.push_back({C,A,B});
    }
    sort(t.begin(),t.end());
    for (int i=0;i<m; i++) {
        auto [cur_weight,node1,node2] = t[i];
        if (find(node1)==find(node2)) {continue;}
        union_find(node1,node2,cur_weight);
    }
    cout<< weight[find(1)];
}