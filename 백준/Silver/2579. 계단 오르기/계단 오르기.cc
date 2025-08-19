#include <bits/stdc++.h>
using namespace std;
int k[1000001][3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int j = 1; j <= n; j++) {
        cin >> k[j][0];
    }
    k[1][1]=k[1][0];
    k[1][2]=0;
    k[2][1]=k[2][0];
    k[2][2]=k[1][0]+k[2][0];
    for (int i = 3; i <= n; i++) {
        k[i][1] = max(k[i - 2][1], k[i - 2][2]) + k[i][0];
        k[i][2] = k[i - 1][1] + k[i][0];
    }
    cout << max(k[n][1],k[n][2]) << "\n";
}
