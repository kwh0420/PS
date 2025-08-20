#include <bits/stdc++.h>
using namespace std;
int dp[1005];
vector<int> buildings[100000];
int building[1005];

int go(int n) {
    if (dp[n]!=-1) return dp[n];
    dp[n]=0;
    for (int i : buildings[n]) {
        dp[n] = max(dp[n],go(i));
    }
    return dp[n]+=building[n];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    fill(dp,dp+1002,-1);
    for (int i=0; i<n; i++) {
        int N,K;
        cin >> N >> K;
        for (int i=1; i<=N; i++) {
            cin >> building[i];
        }
        for (int i=0; i<K; i++) {
            int X,Y;
            cin >> X >> Y;
            buildings[Y].push_back(X);
        }
        int W;
        cin >> W;
        cout << go(W) << '\n';
        fill(dp,dp+1002,-1);
        for (int i=1; i<=N; i++) {
            buildings[i].clear();
        }
    }
}