#include <bits/stdc++.h>
using namespace std;
int N;
int row_dir[4]={-1,0,1,0};
int col_dir[4]={0,1,0,-1};
int visited[21][21];
vector<vector<int>> arr(21,vector<int>(21,0));

vector<vector<int>> ready() {
vector<vector<int>> before_arr(21,vector<int>(21,0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            before_arr[i][j] = arr[i][j];
        }
    }
    return before_arr;
}
void clear(vector<vector<int>> &before_arr) {
    arr=before_arr;
}
void bfs_sub(int row,int col, int mode) {
    while (1) {
        int nrow = row+row_dir[mode];
        int ncol = col+col_dir[mode];

        if (!(0<=nrow && 0<=ncol && nrow<N && ncol<N)) {
            break;
        }
        else if (arr[nrow][ncol]==0) {
            arr[nrow][ncol]=arr[row][col];
            arr[row][col]=0;
        }
        else if (arr[nrow][ncol]==arr[row][col]) {
            if (!visited[nrow][ncol]) {
                arr[nrow][ncol] =arr[row][col]*2;
                arr[row][col]=0;
                visited[nrow][ncol]=1;
            }

            break;
        }

        else {
            break;
        }
        row=nrow;
        col=ncol;
    }

}
void bfs(int mode) {
    if (mode==0||mode==3) {
        for (int i=0; i<N;i++) {
            for (int j=0; j<N; j++) {
                bfs_sub(i,j,mode);
            }
        }
    }
    else if (mode==1||mode==2) {
        for (int i=N-1; i>=0;i--) {
            for (int j=N-1; j>=0;j--) {
                bfs_sub(i,j,mode);
            }
        }
    }
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            visited[i][j]=0;
        }
    }
}
int check() {
    int maxvalue=0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            maxvalue=max(maxvalue, arr[i][j]);
        }
    }
    return maxvalue;
}
int result=0;
int maxval=0;
void func(int n) {
    if (n==5) {
        result = check();
        maxval = max(maxval, result);
    }
    else {
        vector<vector<int>>before(21,vector<int>(21,0));
        before= ready();

        for (int i=0; i<4; i++) {
            bfs(i);
            func(n+1);
            clear(before);
        }
    }
}

int main() {
    cin >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> arr[i][j];
        }
    }

    func(0);
    cout << maxval << endl;
}
