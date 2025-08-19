#include <bits/stdc++.h>
using namespace std;
int main () {
    int dp[1002];
    dp[1]=1;
    dp[2]=2;
    int n=0;
    cin>>n;
    for (int i=3;i<=n;i++) dp[i]=(dp[i-1]+dp[i-2])%10007;
    cout << dp[n] << endl;
}