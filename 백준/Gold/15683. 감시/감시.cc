#include <bits/stdc++.h>
using namespace std;
int N,M;
int arr[9][9];
int row_dir[4]={-1,0,1,0};
int col_dir[4]={0,1,0,-1};
pair<int,int> p[9];
int cctv;
int minvalue=9999999;
int check () {
    int cnt=0;
    for (int i=0; i<N;i++) {
        for (int j=0; j<M;j++) {
            if (arr[i][j]==0) {
                cnt++;
            }
        }
    }
    return cnt;
}
void bfs(int row,int col, int mode) {
    int row_dir_index;
    int col_dir_index;



    int nrow = row + row_dir[mode];
    int ncol = col + col_dir[mode];
    while (0 <= nrow && nrow< N&& 0 <= ncol&& ncol< M) {
        if (arr[nrow][ncol]==6) {
            break;
        }
        else if (arr[nrow][ncol]>0) {
        }
        else {
            arr[nrow][ncol]--; //삽질 포인트 1, 배열을 이전상태로 되돌리려면 단순히 1,0이렇게 하는 것이아닌, 겹치는 경우도 있기 때문에 ++,--로해야함함
        }
        nrow = nrow + row_dir[mode];
        ncol = ncol + col_dir[mode];
    }
}
void clear(int row,int col, int mode) {
    int nrow = row + row_dir[mode];
    int ncol = col + col_dir[mode];
    while (0 <= nrow && nrow< N&& 0 <= ncol&& ncol< M) {
        if (arr[nrow][ncol]==6) {
            break;
        }
        else if (arr[nrow][ncol]<0) {
            arr[nrow][ncol]++;
        }
        else if (arr[nrow][ncol]!=0) {
        }

        nrow = nrow + row_dir[mode];
        ncol = ncol + col_dir[mode];
    }
}
void func(int depth) {

    if (depth == cctv) {
        int result = check();
        if (minvalue>result) {
            minvalue = result;
        }

        return;
    }
    int row = p[depth].first;
    int col = p[depth].second;
    if (arr[row][col]==1) {
        for (int i=0; i<4; i++) {
            bfs(row,col,i);
            func(depth+1);
            clear(row,col,i);
        }
    }
    if (arr[row][col]==2) {
        for (int i=0; i<2; i++) {
            bfs(row,col,i+2);
            bfs(row,col,i);
            func(depth+1);
            clear(row,col,i+2);
            clear(row,col,i);
        }

    }
    if (arr[row][col]==3) { //삽질포인트2, 각 경우를 정확히 구현 안함함
        for (int i=0; i<4; i++) {
            bfs(row,col,i);
            bfs(row,col,(i+1)%4);
            func(depth+1);
            clear(row,col,i);
            clear(row,col,(i+1)%4);
        }


    }
    if (arr[row][col]==4) {
        for (int i=0; i<4; i++) {
            bfs(row,col,i);
            bfs(row,col,(i+1)%4);
            bfs(row,col,(i+2)%4);
            func(depth+1);
            clear(row,col,i);
            clear(row,col,(i+1)%4);
            clear(row,col,(i+2)%4);
        }
    }
    if (arr[row][col]==5) {
        for (int i=0; i<4; i++) {
            bfs(row,col,i);
        }
        func(depth+1);
        for (int i=0; i<4; i++) {
            clear(row,col,i);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++) {
            cin >> arr[i][j];
            if (arr[i][j] != 0 && arr[i][j] != 6) {
                p[cctv++]={i,j};

            }
        }
    }
    func(0);
    cout << minvalue ;
}

