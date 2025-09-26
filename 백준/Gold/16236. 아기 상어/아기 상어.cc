#include <bits/stdc++.h>
using namespace std;
int arr[21][21];
int N;
int cur_row, cur_col;
int cur_size=2, cur_cnt;
int row_dir[4] = {1, 0, -1, 0};
int col_dir[4] = {0, 1, 0, -1};
int result = 0;

tuple<int, int, int> bfs(int cur_row, int cur_col) {
    int vis[21][21];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            vis[i][j] = 0;
        }
    }
    queue<tuple<int, int, int> > q;
    priority_queue<tuple<int, int, int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>> > pq;
    q.push({cur_row, cur_col, 0});
    vis[cur_row][cur_col] = 1;
    while (!q.empty()) {
        auto [cur_row,cur_col,cur_time] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nxt_row = cur_row + row_dir[i];
            int nxt_col = cur_col + col_dir[i];
            if (0 <= nxt_row && nxt_row < N && 0 <= nxt_col && nxt_col < N) {
                if (!vis[nxt_row][nxt_col]) {
                    if (arr[nxt_row][nxt_col]==0 ||arr[nxt_row][nxt_col] <= cur_size) {
                        if (arr[nxt_row][nxt_col] && arr[nxt_row][nxt_col]<cur_size) {
                            pq.push({cur_time+1, nxt_row, nxt_col});
                        }
                        vis[nxt_row][nxt_col] = 1;
                        q.push({nxt_row, nxt_col, cur_time + 1});
                    }
                }
                }
            }
        }
    if (pq.empty()) {return {-1,-1,-1};}
    else {return pq.top();}

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 9) {
                cur_row = i;
                cur_col = j;
                arr[i][j] = 0;
            }
        }
    }
    while (1) {
        auto [nxt_time,nxt_row,nxt_col] = bfs(cur_row, cur_col);

        if (nxt_row == -1 && nxt_col == -1) {
            cout << result;
            return 0;
        }
        cur_row = nxt_row;
        cur_col = nxt_col;
        result += nxt_time;
        arr[cur_row][cur_col] = 0;
        cur_cnt++;
        if (cur_cnt == cur_size) {
            cur_size++;
            cur_cnt = 0;
        }
    }
}
