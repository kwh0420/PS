#include <bits/stdc++.h>
using namespace std;
int N,M;
int arr[10000];
int vis[10000];
int result[10000];
void N_M(int depth,int n) {
    if (depth == M) {
        for (int i=0; i<M; i++) {
            cout << result[i] << " ";

        }
        cout << endl;
    }
    else {
        int temp=0;
        for (int i=n; i<N; i++) {
            if (temp != arr[i]) {
                result[depth]=arr[i];
                temp=arr[i];
                N_M(depth+1,i);
            }
        }
    }
}
int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+N);
    N_M(0,0);
}