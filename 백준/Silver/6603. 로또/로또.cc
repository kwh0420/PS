#include <bits/stdc++.h>
using namespace std;
int N,M;
int arr[100];
int result[100];
int N_M(int depth,int n) {
    if (depth== 6) {
        for (int i = 0; i < 6; i++) {
            cout << result[i] << " ";
        }
        cout << "\n";
        return 0;
    }
    if (n==N){ return 0;}
    result[depth]=arr[n];
    N_M(depth + 1,n+1);

    N_M(depth ,n+1);
    return 0;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (1) {
        cin >> N;
        if (N==0){ break;}
        else {
            for (int i = 0; i < N; i++) {
                cin >> arr[i];
            }
            N_M(0, 0);
            cout << "\n";
        }
    }
}