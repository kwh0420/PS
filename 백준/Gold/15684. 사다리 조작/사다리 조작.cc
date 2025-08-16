#include <bits/stdc++.h>
using namespace std;
bool arr[33][33];
bool arr2[33][33];
int N, M, H;

int maxval;

int bfs(int depth, int row, int i) {
    if (depth == H) {
        if (row == i)
            return 1;
        else
            return 0;
    } else {
        if (1 <= row && arr[depth][row - 1] == 1) {
            return bfs(depth + 1, row - 1, i);
        } else if (row + 1 < N && arr[depth][row] == 1) {
            return bfs(depth + 1, row + 1, i);
        } else {
            return bfs(depth + 1, row, i);
        }
    }
}
int minval=999;
int sum=0;
void f(int depth, int n) {
    if (depth > minval) return;
    sum = 0;

    for (int i = 0; i < N; i++) {
        sum += bfs(0, i, i);
    }
    if (sum == N) {
        minval = min(minval, depth);
        return;
    }
    if (depth==3) {
        return;
    }
    for (int i = n; i < maxval; i++) {
        int row = i / (N-1);
        int col = i % (N-1);
        if (!arr[row][col]) {
           if (1 <= col && arr[row][col - 1] == 1){continue;}
            if (col + 1 < N-1&& arr[row][col + 1] == 1){continue;}
                arr[row][col] = 1;
                f(depth+1, i+1);
                arr[row][col] = 0;

        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> H;
    maxval = (N - 1) * H;
    for (int i = 0; i < M; i++) {
        int m, n;
        cin >> m >> n;
        arr[m - 1][n - 1] = 1;
    }

    f(0, 0);
    cout << ((minval==999)?-1:minval);
}
