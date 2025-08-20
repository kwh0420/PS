#include <bits/stdc++.h>
using namespace std;
int arr[1002][1002];
int dp[1002][1002];
int main() {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        string s;
        cin>>s;
        for(int j=0;j<m;j++) {
            arr[i][j]=s[j]-'0';
        }
    }
    for (int i=0; i<n; i++) {
        dp[i][0]=arr[i][0];
    }
    for (int j=0; j<m; j++) {
        dp[0][j]=arr[0][j];
    }
    for (int i=1; i<n; i++) {
        for (int j=1; j<m; j++) {
            if (arr[i][j]==1)
                dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
        }
    }
    int result=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            result=max(result,dp[i][j]);
        }
    }
    cout << result*result <<'\n';
}