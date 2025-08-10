#include <bits/stdc++.h>
using namespace std;
int N,M,K;
int arr[41][41];
vector<pair<int,int>> v[101][4];
int check(int depth,int r, int c, int mode) {
            for (int z=0; z<v[depth][mode].size(); z++) {
                int row = v[depth][mode][z].first+r;
                int col = v[depth][mode][z].second+c;
                if (!(0<=row && row<N && 0<=col && col<M)||arr[row][col]==1 ) {
                    return 0;
                }
            }
    return 1;
}
void fill(int depth,int r, int c, int mode) {
    for (int z=0; z<v[depth][mode].size(); z++) {
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

        for (int i=0; i<size; i++) {
            int nrow =v[k][0][i].first;
            int ncol =v[k][0][i].second;
            v[k][1].push_back(make_pair(ncol,row-1-nrow));
        }

        for (int i=0; i<size; i++) {
            int nrow =v[k][0][i].first;
            int ncol =v[k][0][i].second;
            v[k][2].push_back(make_pair(row-1-nrow,col-1-ncol));
        }

        for (int i=0; i<size; i++) {
            int nrow =v[k][0][i].first;
            int ncol =v[k][0][i].second;
            v[k][3].push_back(make_pair(col-1-ncol,nrow));
        }

    }
    st(0);


}