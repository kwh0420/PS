#include <bits/stdc++.h>
using namespace std;
int M, N;
int arr[502][502];
int row_dir[4] = {0, 1, 0, -1};
int col_dir[4] = {1, 0, -1, 0};
int result[502][502];
int go(int row, int col) {
    if (result[row][col] != -1) {
        return result[row][col];
    }
    if (row==0 && col == 0) return 1;
    result[row][col]=0;
    for (int i = 0; i < 4; i++) {
        int nrow = row + row_dir[i];
        int ncol = col + col_dir[i];

        if (0 <= row && row < N && 0 <= col && col < M) {
            if (arr[row][col]<arr[nrow][ncol]) {
                result[row][col]+=go(nrow,ncol);
            }
        }
    }
    return result[row][col];

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {

        for (int j = 0; j < M; j++) {
            result[i][j]=-1;
            cin >> arr[i][j];
        }
    }
    cout <<go(N - 1, M - 1);
}
