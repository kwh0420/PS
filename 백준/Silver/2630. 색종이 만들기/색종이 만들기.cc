#include <bits/stdc++.h>
using namespace std;
int arr[129][129];
int row_dir[2]={0,1};
int col_dir[2]={0,1};
int result[2];
int compare (int start_row,int start_col,int N) {
    int value = arr[start_row][start_col];
    for (int i=start_row; i<N+start_row; i++) {
        for (int j=start_col; j<N+start_col; j++) {
            if (arr[i][j] != value)
                return 0;
        }
    }
    return 1;
}
void solve(int start_row,int start_col,int N) {
    if (compare(start_row,start_col,N)) {
        result[arr[start_row][start_col]]++;
        return;
    }


    int nN= N/2;
        for (int i=0; i<2;i++) {
            for (int j=0; j<2;j++) {
                int nrow = start_row + row_dir[i]*nN;
                int ncol = start_col + col_dir[j]*nN;
                solve(nrow,ncol,nN);
            }
        }
    }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    for (int i=0 ;i<N; i++) {
        for (int j=0 ; j<N; j++) {
            cin >> arr[i][j];
        }
    }
    solve(0,0,N);

    for (int i=0; i<2; i++) {
        cout << result[i] << "\n";
    }
}
