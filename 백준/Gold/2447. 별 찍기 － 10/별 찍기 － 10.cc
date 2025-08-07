#include <bits/stdc++.h>
using namespace std;
int row_dir[3] = {0,1,2};
int col_dir[3]={0,1,2};
char arr[6562][6562];
void solve(int start_row,int start_col,int N) {
    if (N==3) {
        for (int i=start_row; i<start_row+N; i++) {
            for (int j=start_col; j<start_col+N; j++) {
                if (i!=start_row+1 || j!=start_col+1)
                    arr[i][j]='*';
            }
        }
    }
    else {
        int nN= N/3;
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                if (i!=1 || j!=1)
                    solve(start_row+row_dir[i]*nN,start_col+col_dir[j]*nN,nN);
            }
        }
    }
}

int main () {
    int N;
    cin>>N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            arr[i][j]=' ';
        }
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve(0,0,N);
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cout << arr[i][j];
        }
        cout << '\n';
    }
}