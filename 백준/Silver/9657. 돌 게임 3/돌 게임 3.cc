#include <bits/stdc++.h>
using namespace std;
int N;
bool dp[1000000];
int main() {
    cin >> N;
    dp[1]=1;
    dp[2]=0;
    dp[3]=1;
    dp[4]=1;
    for (int i = 5; i <= N; i++) {
        dp[i]=!min(dp[i-1],min(dp[i-3],dp[i-4]));
    }

    cout << ((dp[N]%2)?"SK":"CY");

}