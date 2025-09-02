#include <bits/stdc++.h>
using namespace std;
int N,M;
int row_dir[8]={1,1,1,0,0,-1,-1,-1};
int col_dir[8]={-1,0,1,-1,1,1,0,-1};
char check_arr[3]={'F','O','X'};
char arr[102][102];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> arr[i][j];
        }
    }
    int cnt=0;

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            for (int k=0; k<8; k++) {
                int row=i;
                int col=j;
                for (int l=0; l<3; l++) {
                    if (!(0<=row&&row<N&&0<=col&&col<M)){break;}
                    if (arr[row][col]!=check_arr[l]) {
                        break;
                    }
                    row+=row_dir[k];
                    col+=col_dir[k];
                    if (l==2) {

                        cnt++;
                    }
                }
            }
        }
    }
    cout << cnt;
}
