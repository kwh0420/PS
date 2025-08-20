#include <bits/stdc++.h>
using namespace std;
int N;
int K;
int W[102];
int V[102];
int dp[102][100002];
int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> W[i]>>V[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= K; j++) {
            if (i-1>=0)
                dp[i][j] = dp[i-1][j];
            if (j-W[i]>=0)
                if(i-1>=0)
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-W[i]]+V[i]);
                else
                    dp[i][j]=V[i];
        }
    }
    cout << dp[N-1][K];
}