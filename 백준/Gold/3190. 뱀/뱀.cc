#include <bits/stdc++.h>
using namespace std;
int arr[102][102];
int K=0;
int N=0;
char X[10002];
int row_dir[4]={0,1,0,-1};
int col_dir[4]={1,0,-1,0};
int vis[102][102];
int main(){
    ios_base::sync_with_stdio(false);

    cin.tie(NULL);
    cin >> N;
    cin >> K;
    for (int i=0; i<K; i++) {
        int m,n;
        cin >> m >> n;
        arr[m-1][n-1] = 1;
    }
    int L;
    cin >> L;
    for (int i=0; i<L; i++) {
        int n;
        char k;
        cin >> n >> k;
        X[n]=k;
    }
    deque<pair<int,int> > q;
    vis[0][0]=1;
    q.push_front(make_pair(0,0));
    int d=0;
    int game_time=0;
    while (1) {
        if (X[game_time]!=0) {
            char nd= X[game_time];
            if (nd=='L') {
                d=(d+3)%4;
            }
            else if (nd=='D') {
                d=(d+1)%4;
            }
        }
        int nrow = q.front().first+ row_dir[d];
        int ncol = q.front().second + col_dir[d];
        if (!(0<=nrow && nrow<N && 0<=ncol && ncol<N)||(vis[nrow][ncol]==1)) {
            cout << game_time+1;
            return 0;
        }
        else {
            q.push_front({nrow,ncol});
            vis[nrow][ncol]=1;
        }
        if (!(arr[nrow][ncol]==1)) {
            vis[q.back().first][q.back().second] = 0;
            q.pop_back();
        }
        else {
            arr[nrow][ncol] = 0;
        }
        game_time++;
    }
}