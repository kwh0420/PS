#include <bits/stdc++.h>
using namespace std;
int N,M;
int arr[10][10];
int vis[10][10];
int idx[100];
int temp[100];
int row_dir[4]={0,1,0,-1};
int col_dir[4]={1,0,-1,0};
int bfs(int i, int j) {
    if (vis[i][j] || arr[i][j]==0 || arr[i][j]==1) {
        return 0;
    }
    queue<pair<int, int>> q;
    int cnt = 0;
    q.push(make_pair(i, j));
    cnt ++;
    vis[i][j] = 1;
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nrow = p.first + row_dir[i];
            int ncol = p.second + col_dir[i];
            if (0<=nrow && nrow<N && 0<=ncol && ncol<M) {
                if (arr[nrow][ncol] == 0 || arr[nrow][ncol] == 2) {
                    if (vis[nrow][ncol] == 0) {
                        q.push(make_pair(nrow, ncol));
                        vis[nrow][ncol] = 1;
                        cnt++;
                    }
                }
            }
        }
    }
    return cnt;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    int k=0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> arr[i][j];
            if (arr[i][j]==1) {
                k++;
            }
        }
    }
    int index=0;
    temp[N*M-1]=1;
    temp[M*N-2]=1;
    temp[M*N-3]=1;
int max_sum=99999;
    do {
        int sum=0;
        int copy[10][10]={0};
        memcpy(copy,arr,sizeof(arr));
        for (int i=0; i<N ; i++) {
            for (int j=0; j<M ; j++) {
                if (temp[i*M+j]==1 &&arr[i][j]!=2) {
                    arr[i][j]=1;
                }
            }
        }
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                sum+=bfs(i,j);
            }
        }

        memcpy(arr,copy,sizeof(arr));
        for (int i=0; i<N ; i++) {
            for (int j=0; j<M ; j++) {
                vis[i][j]=0;
            }
        }
        max_sum= min(max_sum,sum);
    }while (next_permutation(temp,temp+N*M));
    cout << N*M-max_sum-k-3  ;
}