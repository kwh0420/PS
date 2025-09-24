#include <bits/stdc++.h>
using namespace std;
int arr[502];
int d[502][502];
int sum[502][502];
int nxt[502];
int dp(int i, int j) {
    if (d[i][j]){return d[i][j];}
    if (i==j) {return 0;}
    int minval=1e9;
    int totalsum=0;
    for (int k=i;k<=j;k++) {
        totalsum+=arr[k];
    }
    for (int k=i; k<j; k++) {
        int r = dp(i, k)+dp(k+1,j)+totalsum;
        minval = min(r,minval);
    }
    return d[i][j] = minval;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        int k;
        cin>>k;
        for(int j=0;j<k;j++) {
            cin>>arr[j];
        }
        cout << dp(0,k-1)<< "\n";
        for(int j=0;j<k;j++) {
            for (int p=0; p<k; p++) {
                d[j][p]=0;
            }
        }
    }
}