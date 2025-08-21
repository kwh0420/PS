#include <bits/stdc++.h>
using namespace std;
long long int dp[5003][2];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    int size= s.length();
    if (s[0]=='1' || s[0]=='2') {
        dp[0][0]=1;
    }
    else if (s[0]=='0') {
        cout << 0;
        return 0;
    }
    else
        dp[0][1]=1;
    for (int i=1; i<size; i++) {
        char before=s[i-1];
        char cur=s[i];
        if (before=='1' || before == '2') {
            if (cur=='0') {
                dp[i][0]=0;
                dp[i][1]=dp[i-1][0];
            }
            else if (cur=='1' || cur=='2') {
                dp[i][0]=(dp[i-1][0]+dp[i-1][1])% 1000000;
                dp[i][1]=dp[i-1][0];
            }
            else if (cur == '3'||cur=='4'||cur=='5'||cur=='6') {
                dp[i][0]=0;
                dp[i][1]=(dp[i-1][1]+(dp[i-1][0]*2)% 1000000);
            }
            else if (before == '2') {
                dp[i][0]=0;
                dp[i][1]=(dp[i-1][1]+dp[i-1][0])% 1000000;
            }
            else if (before =='1') {
                dp[i][0]=0;
                dp[i][1]=(dp[i-1][1]+(dp[i-1][0]*2)% 1000000)% 1000000;
            }
        }
        else {
            if (cur=='0') {
                cout << 0;
                return 0;
            }
            if (cur=='1' || cur=='2') {
                dp[i][0]=dp[i-1][1];;
            }
            else {
                dp[i][1]=dp[i-1][1];
            }
        }
        dp[i][0]%= 1000000;
        dp[i][1]%= 1000000;

    }
    cout << (dp[s.length()-1][0]% 1000000+dp[s.length()-1][1]% 1000000)% 1000000 << "\n";
}