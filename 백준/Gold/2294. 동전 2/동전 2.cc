#include <bits/stdc++.h>
using namespace std;
int n,k;
vector<int> v;
int dp [102][10000];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for (int i=0; i<n; i++) {
        for (int j=0; j<=k; j++) {
            dp[i][j]=999999;
        }
    }
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
        dp[i][a]=1;
    }
    for (int i=0; i<n; i++) {
        for (int j=1; j<=k; j++) {
            if (i-1>=0) {
                dp[i][j] = min(dp[i][j],dp[i-1][j]);

            }
            if (j-v[i]>=0) {
                dp[i][j]=min(dp[i][j],dp[i][j-v[i]]+1);
            }
        }
    }

    cout << (dp[n-1][k]==999999?-1:dp[n-1][k]) << endl;
}