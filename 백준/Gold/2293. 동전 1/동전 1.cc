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
                dp[v] += dp[v-coin[idx]]; // 2차원 dp가아닌 1차원 dp로 풀어야함. 동전을 크기순으로 정렬한 후, 초기값으로 1을 준다. 10000*100 = 약4mb로 문제조건에 아슬아슬하기때문
        }
    }
    cout << dp[k];

}
