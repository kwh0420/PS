#include <bits/stdc++.h>
using namespace std;
int ret, n, m;
int A[1000][1000], B[1000][1000], diff[1000];
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> B[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        int mx = -987654321;
        for (int j = 0; j < n; j++) {
            mx = max(mx, abs(A[j][i]-B[j][i]));
        }
        diff[i] = mx;
    }
    for (int i = 0; i < m; i++) {
        int idx; cin >> idx;
        idx--;
        ret += diff[idx];
    }
    cout << ret << '\n';
}