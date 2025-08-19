#include <bits/stdc++.h>
using namespace std;
int N,M;
int arr[100003];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i=1; i<=N; i++) {
        cin >> arr[i];
        if (i>=1)
        arr[i]=arr[i]+arr[i-1];
    }
    for (int i=0; i<M; i++) {
        int q;
        int w;
        cin >> q >> w;
        cout << arr[w]-arr[q-1]<<"\n";
    }
}