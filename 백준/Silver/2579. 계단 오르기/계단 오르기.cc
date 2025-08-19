#include <bits/stdc++.h>
using namespace std;
int k[1000001];
int s[1000001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int sum=0;
    for (int i=1; i<=n; i++) {
        cin >> s[i];
        sum+=s[i];
    }
    k[1]=s[1];
    k[2]=s[2];
    k[3]=s[3];
    for (int i=4; i<=n; i++) {
        k[i]+=min(k[i-2],k[i-3])+s[i];

    }
    cout << sum-min(k[n-1],k[n-2]);
}
