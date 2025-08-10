#include <bits/stdc++.h>
using namespace std;
int N,M,K;
int arr[41][41];
vector<pair<int,int>> v[101][4];
int check(int depth,int r, int c, int mode) {
            for (int z=0; z<v[depth][mode].size(); z++) {
                int row = v[depth][mode][z].first+r;
                int col = v[depth][mode][z].second+c;
                // [변경] 범위 체크를 arr 접근 전에 수행하도록 순서 변경
                // 기존: arr[row][col] == 1 || 범위 밖  → 범위 밖일 때 접근 오류 가능성 있었음
                if (!(0<=row && row<N && 0<=col && col<M)||arr[row][col]==1 ) {
                    return 0;
                }
            }
    return 1;
}
void fill(int depth,int r, int c, int mode) {
    for (int z=0; z<v[depth][mode].size(); z++) {
        // [변경] 잘못된 인덱스 순서(v[depth][z][mode]) → 올바른 순서(v[depth][mode][z])로 수정
        int row = v[depth][mode][z].first+r;
        int col = v[depth][mode][z].second+c;
        arr[row][col]=1;
    }
    return;
}
void st(int depth) {
    if (depth==K) {
        int cnt=0;
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (arr[i][j]==1) {
                    cnt++;
                }
            }

        }
        cout << cnt;
        exit(0);
    }
    for (int mode =0; mode<4; mode++){
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (check(depth,i,j,mode)) {
                fill(depth,i,j,mode);
                st(depth+1);
                return;
            }
        }
    }

    }
    st(depth+1);
    return;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> N >> M >> K;
    for (int k = 0; k < K; k++) {
        int row,col;
        cin >> row >> col;

        for (int i=0;i<row;i++) {
            for (int j=0;j<col;j++) {
                int input;
                cin >> input;
                if (input==1) {
                    v[k][0].push_back(make_pair(i,j));
                }
            }
        }
        int size=v[k][0].size();

        // [변경] 스티커 회전 시 기존 코드에서 비어 있는 v[k][1], v[k][2], v[k][3]를 참조하던 버그 수정
        //       모든 회전은 원본 모양 v[k][0]을 기반으로 계산하도록 변경

        // 시계방향 90도 회전
        for (int i=0; i<size; i++) {
            int nrow =v[k][0][i].first;
            int ncol =v[k][0][i].second;
            v[k][1].push_back(make_pair(ncol,row-1-nrow));
        }

        // 시계방향 180도 회전
        for (int i=0; i<size; i++) {
            int nrow =v[k][0][i].first;
            int ncol =v[k][0][i].second;
            v[k][2].push_back(make_pair(row-1-nrow,col-1-ncol));
        }

        // 시계방향 270도 회전
        for (int i=0; i<size; i++) {
            int nrow =v[k][0][i].first;
            int ncol =v[k][0][i].second;
            v[k][3].push_back(make_pair(col-1-ncol,nrow));
        }

    }
    st(0);
}
