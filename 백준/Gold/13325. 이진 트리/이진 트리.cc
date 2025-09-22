#include <bits/stdc++.h>
using namespace std;
long long int N;
#define ll long long int
ll p2[23];
int maxval = 0;
long long int arr[1<<23];
ll sum = 0;

int dfs(int i) {
    if (i > maxval) { return 0; }
    ll a1 = dfs(i * 2 + 1);
    ll a2 = dfs(i * 2 + 2);
    if (a1 < a2) {
        arr[i * 2 + 1] += a2 - a1;
        return a2 + arr[i];
    }
    arr[i * 2 + 2] += a1 - a2;
    return a1 + arr[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    p2[0] = 1;
    for (long long int i = 1; i < 23; i++) {
        p2[i] = 1;
        p2[i] = p2[i - 1] * 2;
    }

    cin >> N;
    maxval = 2 * (p2[N] - 1);
    for (long long int i = 1; i <= 2 * (p2[N] - 1); i++) { cin >> arr[i]; }
    dfs(0);
    for (long long int i = 1; i <= 2 * (p2[N] - 1); i++) {
        sum += arr[i];
    }
    cout << sum;
}
