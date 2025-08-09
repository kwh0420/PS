#include <bits/stdc++.h>
using namespace std;
int N,M;
int arr[10];
void N_M(int depth) {
    if (depth == M) {
        for (int i=0; i<M; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    else {
        for (int i=1; i<=N ; i++) {
            arr[depth]=i;
            N_M(depth+1);
        }
    }
}
int main () {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    N_M(0);
}