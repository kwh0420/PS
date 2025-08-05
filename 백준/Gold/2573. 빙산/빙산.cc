#include <bits/stdc++.h>
using namespace std;
#define row first
#define col second
int map_arr[302][302];
int N,M;
int zero[302][302];
int row_dir[4]={1,0,-1,0};
int col_dir[4]={0,1,0,-1};
int visited[302][302];
int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map_arr[i][j];
            visited[i][j]=-1;
        }
    }

    int area=0;
    int re=-1;

    while (1) {
        re++;
        area=0;
        int boom=0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map_arr[i][j] == 0||visited[i][j]==re) {
                    continue;
                }
                queue<pair<int, int>> q;
                q.push({i,j});
                visited[i][j] = re;
                while (!q.empty()) {
                    pair<int, int> p = q.front();
                    q.pop();
                    for (int i=0; i<4; i++) {
                        int nrow = p.row+row_dir[i];
                        int ncol = p.col+col_dir[i];
                        if (nrow >= 0 && nrow < N && ncol >= 0 && ncol < M &&  visited[nrow][ncol] != re && map_arr[nrow][ncol]>0) {
                            q.push({nrow,ncol});
                            visited[nrow][ncol] = re;
                        }
                    }
                }
                area++;
            }
        }


        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                zero[i][j]=0;
            }
        }
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (map_arr[i][j]==0) {
                    for (int z=0; z<4 ;z++) {
                        int nrow = i+row_dir[z];
                        int ncol = j+col_dir[z];
                        if (nrow >= 0 && nrow < N && ncol >= 0 && ncol < M ) {
                            zero[nrow][ncol]++;
                        }
                    }
                }
            }
        }
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (map_arr[i][j]>zero[i][j]) {
                    map_arr[i][j]-=zero[i][j];
                }
                else {
                    map_arr[i][j]=0;
                }
                if (map_arr[i][j]==0) {
                    boom++;
                }
            }
        }

        if (area>=2) {
            cout <<  re;
            return 0;

        }
        else if (boom == N*M) {
            cout << 0 ;
            return 0;
        }
    }

}