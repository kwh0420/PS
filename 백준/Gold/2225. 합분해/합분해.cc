#include <bits/stdc++.h>
using namespace std;
long long int N,K;
long long int DP[202][202];
 int main() {
    cin >> N >> K;
    for (long long int i = 0; i <= N; i++) {
        DP[i][1]=1;
        for (long long int j = 2; j <= K; j++) {
            for (long long int k = 0; k <= i; k++) {
                DP[i][j]=(DP[i][j]+DP[i-k][j-1])%1000000000;
            }
        }
    }
    cout << DP[N][K];
}