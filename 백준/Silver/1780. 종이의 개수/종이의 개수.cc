#include <bits/stdc++.h>
using namespace std;
#define ll long long
int arr[2188][2188];
int N;
int row_dir[3] = {0,1,2};
int col_dir[3] = {0,1,2};
int result[3];
bool compare(int start_row,int start_col,int N) {
    int value = arr[start_row][start_col];
    for (int i=start_row ; i<start_row +N ; i++) {
        for (int j=start_col; j<start_col+N ; j++) {
            if (arr[i][j]!=value) {
                return false;
            }
        }
    }
    return true;
}
void solve(int start_row,int start_col, int N) {
    int same=1;

    
    if (compare(start_row,start_col,N)) {
        result[arr[start_row][start_col]+1]++;
    }
    else {
        for (int i=0; i<3; i++) {
            for (int j=0; j<3 ; j++) {
                int nN= N/3;
                int nrow = start_row + row_dir[i]*nN;
                int ncol = start_col + col_dir[j]*nN;
                solve(nrow,ncol,nN);
            }
        }
    }


}
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
    solve(0,0,N);
    for (int i=0; i<3; i++) {
        cout << result[i];
        cout <<'\n';
    }
}