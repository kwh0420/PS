#include <bits/stdc++.h>
using namespace std;
int dp[22][10002];
int c[22];
int N,M;

int T;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        for (int i=0; i<N; i++) {
            cin >> c[i];
            dp[i][0]=1;
        }
        cin >>M;
        for (int i=0; i<N; i++) {
            for (int j=1; j<=M; j++) {
                dp[i][j]=0;
                if (i-1>=0)
                    dp[i][j]+=dp[i-1][j];
                if (j-c[i]>=0)
                    dp[i][j]=dp[i][j]+dp[i][j-c[i]];
            }
        }
        cout << dp[N-1][M] << '\n';
    }
}
