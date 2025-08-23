#include <bits/stdc++.h>
using namespace std;
int dp[1002];
map<pair<int,int>, int> w;
vector<int> v[1002];
int N,M;
int go(int cur, int par) {
    if (v[cur].size()==1 && cur != 1) { // cur!=1을 추가해주지 않아서 , 1-2 처럼 총 노드의 개수가 2일때의 경우를 커버해주지 못했음
        return 999999;
    }
    int sumsum=0;
    for (int i : v[cur]) {
        if (i==par) { 
            continue;
        }
        sumsum += min(go(i,cur),w[{cur,i}]);

    }
    return dp[cur]=sumsum;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> N >>M;

        for (int i=1; i<=N; i++) {
            dp[i]=999999;
        }
        for (int i = 0; i < M; i++) {
            int a,b,d;
            cin >> a >> b >> d;
            v[a].push_back(b);
            v[b].push_back(a);
            w[{a,b}]=d;
            w[{b,a}]=d;

        }
        cout << go(1,0) << "\n";
        for (int i=0; i<1002; i++) {
            v[i].clear();
        }
        w.clear();
    }

}
