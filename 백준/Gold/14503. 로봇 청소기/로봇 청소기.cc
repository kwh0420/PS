#include <bits/stdc++.h>
using namespace std;
int N,M;
int d;
int start_N,start_M;
int arr[51][51];
int vis[51][51];
int row_dir[4]={-1,0,1,0};
int col_dir[4]={0,1,0,-1};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>M;
    cin>>start_N>>start_M>>d;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin>>arr[i][j];
        }
    }
    int row=start_N,col=start_M;
    int re=0;
    vis[row][col]=1;
    int cnt=0;
    cnt++;
    while (1){
        re=0;
        int vision =d;
        for (int i=0; i<4; i++) {
            vision=(vision-1+4)%4; // 회전을 언제할지에 따라 답이 달라짐
            int nrow=row+row_dir[vision];
            int ncol=col+col_dir[vision];
            if (0<=nrow&&nrow<N&&0<=ncol&&ncol<M&&vis[nrow][ncol]==0&&arr[nrow][ncol]==0) { //문제 풀때는 몰랐지만 맵 테두리가 전부 벽으로 둘러 싸여 있어서 nrow,ncol에 범위 조건을 달 필요가 없었음.
                vis[nrow][ncol]=1;
                row=nrow;
                col=ncol;
                re=1;
                cnt++;
                d=vision;
                break;
            }
            //원래는 회전 코드가 여기 있었음
        }
        if (re==1) {
            continue;
        }
        else {
            int nrow = row+row_dir[(d+2)%4];
            int ncol = col+col_dir[(d+2)%4];
            if (0<=nrow&&nrow<N&&0<=ncol&&ncol<M && arr[nrow][ncol]==0) {
                row=nrow;
                col=ncol;
                continue;
            }
            else {
                break;
            }
        }

    }
    cout << cnt;
}


