#include <bits/stdc++.h>
using namespace std;
int dp[10002];
int coin[102];
int n,k;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>k;
    for(int i=0;i<n;i++){cin >> coin[i];}
    sort(coin,coin+n);
    for (int idx =0; idx<n; idx++) {
        if (coin[idx]>10000)continue;
        dp[coin[idx]]+=1;
        for (int v = 0; v <= k; v++) {
            if (v-coin[idx]>=0)
                dp[v] += dp[v-coin[idx]];
        }
    }
    cout << dp[k];
}