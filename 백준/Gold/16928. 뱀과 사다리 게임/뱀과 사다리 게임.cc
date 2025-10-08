#include <bits/stdc++.h>
using namespace std;
map<int,int> snake;
map<int,int> ladder;
int vis[102];
vector<int> path(102,1e9);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        int a,b;
        cin >> a >> b;
        ladder[a] = b;

    }
    for (int i = 1; i <= M; i++) {
        int a,b;
        cin >> a >> b;
        snake[a] = b;
    }
   queue<int> q;
    q.push(1);
    path[1] = 0;
    while (!q.empty()) {
        int v = q.front();

        if (v==100){cout << path[v];return 0;}
        q.pop();
        for (int i = 1; i <= 6; i++) {
            int ninx=v+i;
            if (v+i>100){continue;}
            if (snake.count(v+i)) {ninx = snake[v+i];}
            if (ladder.count(v+i)) {ninx = ladder[v+i];}
            if (path[ninx]<path[v]+1){continue;}

            q.push(ninx);
            path[ninx] = path[v]+1;
        }
    }
}