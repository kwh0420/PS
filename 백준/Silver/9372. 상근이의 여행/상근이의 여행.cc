#include <bits/stdc++.h>
using namespace std;
vector<long long int> par(302,-1);
int find(long long int target) {
    if (par[target]<0)return target;
    return par[target] = find(par[target]);
}
long long int union_find(long long int i,long long int j) {
    i= find(i);
    j= find(j);
    if (i==j)return 0;
    if (par[i]>par[j])swap(i,j);
    if (par[i]==par[j])par[i]--;
    par[j]=i;
    return 1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--) {
        int N, M;
        cin>>N>>M;
        par.assign(N,-1);

        vector<pair<int,int>> t;
        for(int i=0;i<M;i++) {
            int a,b;
            cin>>a>>b;
            t.push_back({a,b});
        }
        cout << N-1 <<"\n";
    }
}