#include <bits/stdc++.h>
using namespace std;
long long int dp[31];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    dp[2]=3;
    int n=0;
    for (int i=2; i<=15;i++){
        dp[i*2]=2+dp[(i-1)*2]*3;
        for (int j=2;j<i ;j++) {
            dp[i*2]+=dp[(i-j)*2]*2;
        }
    }
    cin >> n;
    cout << dp[n];
}