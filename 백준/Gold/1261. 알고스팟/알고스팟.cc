#include <bits/stdc++.h>
using namespace std;
int arr[102][102];
int dist[102][102];
int row_dir[4]= {0,1,0,-1};
int col_dir[4]= {1,0,-1,0};
const int INF = 1e9;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin >> M >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < M; j++) {
            arr[i][j]=s[j]-'0';
            dist[i][j]=INF;
        }

    }
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
    pq.push({0,0,0});
    dist[0][0]=0;
    while (!pq.empty()) {
        tuple<int,int,int> p;
        p = pq.top();
        pq.pop();
        int cur_w = get<0>(p);
        int cur_row = get<1>(p);
        int cur_col = get<2>(p);
        if (dist[cur_row][cur_col] != cur_w) {continue;}
        for (int i=0; i<4; i++) {
            int next_row = cur_row + row_dir[i];
            int next_col = cur_col + col_dir[i];
            if (next_row >= 0 && next_row < N && next_col >= 0 && next_col < M) {
                if (arr[next_row][next_col]+cur_w < dist[next_row][next_col]) {
                    pq.push({cur_w+arr[next_row][next_col], next_row, next_col});
                    dist[next_row][next_col] = cur_w+arr[next_row][next_col];
                }
            }
        }
    }
    cout << dist[N-1][M-1];
}