#include <bits/stdc++.h>
using namespace std;
int N;
int dp[1000000];
int main() {
    cin >> N;
    for (int i=1; i<=400; i++) {
        dp[i*i]=1;
    }
    for (int i = 1; i <= N; i++) {
        dp[i]=i;
        for (int j=1; j*j<=i; j++) {
            dp[i]=min(dp[i], dp[i-j*j]+1); // i보다 작은 모든 제곱수를 고려해야함. d[i]=[i]로 초기값설정, 처음엔 i보다 처음으로 작은 수만 고려했음.
        }
    }
    cout << dp[N];


}
