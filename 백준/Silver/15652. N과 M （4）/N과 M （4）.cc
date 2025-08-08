#include <bits/stdc++.h>
using namespace std;
int N,M;
int arr[10];
int compare(int k) {
    for (int i=0; i<k-1; i++) {
        if (arr[i]>arr[i+1]) {
            return 0;
        }
    }
    return 1;
}
void N_M(int k, int n) {
    if (k==M) {
        if (compare(k)) {
            for (int i=0; i<M; i++) {
                cout << arr[i] << " ";
            }
            cout << "\n";
            return;
        }
        return;
    }
    else {
        for (int i=n; i<=N; i++) {
            arr[k]=i;
            N_M(k+1,i);

        }
    }
}
int main() {
    cin >> N>>M;
    N_M(0,1);
}