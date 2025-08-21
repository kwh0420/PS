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
    for (int i = 1; i <= N; i++) { // (1,1)부터 입력을 받고 가장자리는 0으로 채운다면 케이스를 불필요하게 나눌 필요가 없음
        for (int j = 1; j <= N; j++) {
            cin >> dp[i][j];
        }
    }
    for (int i = 2; i <= N; i++) {
        dp[i][1] += dp[i - 1][1];
        dp[1][i] += dp[1][i - 1];
    }

    for (int i = 2; i <= N; i++) {
        for (int j = 2; j <= N; j++) {
            dp[i][j] += dp[i][j - 1] + dp[i - 1][j]-dp[i-1][j-1];
        }
    }

    for (int i = 0; i < M; i++) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1;
        cin >> x2 >> y2;

            cout << dp[x2][y2]+dp[x1-1][y1-1]-dp[x1-1][y2]-dp[x2][y1-1]<<'\n';

    }
}
