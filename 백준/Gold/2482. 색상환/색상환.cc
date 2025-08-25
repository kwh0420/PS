#include <limits>
#include <bits/stdc++.h>
using namespace std;
int N,K;
int dp[1002][1002];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    dp[1][1]=1;
    dp[2][1]=2;
    dp[3][1]=3;
    for (int i=4; i<=N; i++) {
        dp[i][1]=i;
        for (int j=2; j*2<=i; j++) {
            dp[i][j]=(dp[i-2][j-1]+dp[i-1][j])%1000000003;
        }
    }

    cout <<dp[N][K];
}
