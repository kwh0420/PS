#include <bits/stdc++.h>
using namespace std;
int arr[51][51];
int visited[51][51];
#define row first
#define col second
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int R;
    cin >> R;
    for (int i = 0; i < R; i++) {
        int N,M,K;
        cin >> N >> M>>K;
        for (int j = 0; j < K; j++) {
            int a,b;
            cin >> a >> b;
            arr[a][b] = 1;
        }
        int area=0;
        for (int i = 0; i < N; i++) {
            for (int j=0; j<M; j++) {
                if (visited[i][j]==1 || arr[i][j]==0) {
                    continue;
                }
                area++;
                stack <pair <int, int> > s;
                s.push({i,j});
                visited[i][j] = 1;

                while (!s.empty()) {
                    pair <int, int> p = s.top();
                    s.pop();
                    for (int k = 0; k < 4; k++) {
                        int nrow = p.row + dx[k];
                        int ncol = p.col + dy[k];
                        if (0<=nrow && nrow<=N && 0<=ncol && ncol<M && arr[nrow][ncol]==1&& visited[nrow][ncol]==0) {
                            s.push({nrow,ncol});
                            visited[nrow][ncol] = 1;
                        }
                    }
                }

            }
        }
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                visited[i][j] = 0;
                arr[i][j]=0;
            }
        }
        cout << area <<"\n";
    }
}