#include <bits/stdc++.h>
using namespace std;
int N;
int dp[1025][1025];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    int M;
    cin >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> dp[i][j];
        }
    }
    for (int i = 1; i < N; i++) {
        dp[i][0] += dp[i - 1][0];
        dp[0][i] += dp[0][i - 1];
    }

    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {
            dp[i][j] += dp[i][j - 1] + dp[i - 1][j]-dp[i-1][j-1];
        }
    }

    for (int i = 0; i < M; i++) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1;
        cin >> x2 >> y2;
        if (x1==1) {
            cout << dp[x2-1][y2-1]-dp[x2-1][y1-2] <<'\n';
        }
        else if (y1==0) {
            cout << dp[x2-1][y2-1]-dp[x1-2][y2-1] << '\n';

        }
        else {
            cout << dp[x2-1][y2-1]+dp[x1-2][y1-2]-dp[x1-2][y2-1]-dp[x2-1][y1-2]<<'\n';
        }
    }
}
