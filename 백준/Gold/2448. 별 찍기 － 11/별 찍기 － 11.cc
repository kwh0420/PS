#include <bits/stdc++.h>
using namespace std;
int row_dir[3] = {0,1,1};
int col_dir[3]={1,0,2};
char arr[6562][6562];
int answer_row[8] = {0,1,1,2,2,2,2,2};
int answer_col[8] = {2,1,3,0,1,2,3,4};
void solve(int start_row,int start_col,int N) {
    if (N==3) {
        for (int i=0; i<8; i++) {
            arr[start_row+answer_row[i]][start_col+answer_col[i]] = '*';
        }
    }
    else {
        int nN= N/2;
        int col_N = N/2;
        for (int i=0; i<3; i++) {
            solve(start_row+row_dir[i]*nN,start_col+col_dir[i]*col_N,nN);
        }
    }
}

int main () {
    int N;
    cin>>N;
    int col_N = 2*N-1;

    for (int i=0; i<N; i++) {
        for (int j=0; j<col_N; j++) {
            arr[i][j]=' ';
        }
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve(0,0,N);
    for (int i=0; i<N; i++) {
        for (int j=0; j<col_N; j++) {
            cout << arr[i][j];
        }
        cout << '\n';
    }
}