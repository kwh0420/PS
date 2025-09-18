#include <bits/stdc++.h>
using namespace std;
int arr[1002];
int dp[1002];
vector<int> before(1002,-1);

int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++){cin >> arr[i];}
    for(int i=0;i<n;i++) {
        for (int j=0;j<i;j++) {
            if (arr[i]>arr[j]) {
                if (dp[i] < dp[j] + 1) {
                    dp[i]=dp[j] + 1;
                    before[i]=j;
                }
            }
        }
    }
    vector<int> v;
    int cur=0;
    int maxLen = 0;
    for(int i=0;i<n;i++){
        if(dp[i] > maxLen){
            maxLen = dp[i];
            cur = i;
        }
    }
    while (cur != -1){v.push_back(arr[cur]);cur=before[cur];}
    cout << v.size() << "\n";
    for (int i=v.size()-1;i>=0;i--) {cout << v[i] <<" ";}
}