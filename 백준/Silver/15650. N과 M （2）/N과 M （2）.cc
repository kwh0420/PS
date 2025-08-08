#include <bits/stdc++.h>
using namespace std;
int arr[10];
int visited[10];
int N,M;
int check() {
    for (int i = 0; i < M-1; i++) {
        if (arr[i]>arr[i+1]) {
            return 0;
        }
    }
    return 1;
}
int N_M(int row) {
    if (row == M) {
        if (check()) {
            for (int i = 0; i < M; i++) {
                cout << arr[i] << " ";
            }
            cout<<"\n";
        }

        return 1;
    }

    else {
        for (int i=1; i <= N; i++) {
            if (visited[i] == 1) {
                continue;
            }
            visited[i] = 1;
            arr[row] = i;
            N_M(row+1);
            visited[i] = 0;

        }
    }
    return 1;
}

int main() {
 cin>> N>>M;
    N_M(0);
}
