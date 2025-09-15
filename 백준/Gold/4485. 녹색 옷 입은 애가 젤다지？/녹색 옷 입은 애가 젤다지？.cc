#include <bits/stdc++.h>
using namespace std;
int N;
int row_dir[4] = {0,1,0,-1};
int col_dir[4] = {1,0,-1,0};
int main() {
    int cnt=0;
    while (1) {
        ios::sync_with_stdio(0);
        cin.tie(NULL);
        cnt++;
        int N;
        cin >> N;
        if (N == 0) {
            break;
        }
        int matrix[N][N];
        int dist[N][N];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> matrix[i][j];
                dist[i][j]=1e9;
            }
        }
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        pq.push({matrix[0][0], 0,0});
        dist[0][0]=matrix[0][0];
        while (!pq.empty()) {
            auto[cur_weight,cur_row,cur_col] = pq.top();
            if (cur_weight != dist[cur_row][cur_col])continue;
            pq.pop();
            for (int i=0; i<4; i++) {
                int next_row = cur_row + row_dir[i];
                int next_col = cur_col + col_dir[i];
                if (next_row >= 0 && next_row < N && next_col >= 0 && next_col < N) {
                    int next_weight = cur_weight + matrix[next_row][next_col];
                    if (dist[next_row][next_col]<=next_weight) {continue;}
                    dist[next_row][next_col] = next_weight;
                    pq.push({next_weight, next_row, next_col});
                }
            }
        }
        cout << "Problem "<<cnt<<": "  << dist[N-1][N-1] << "\n";
    }
}