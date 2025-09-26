#include <bits/stdc++.h>
using namespace std;
int R,C;
char arr[21][21];
int check_arr[26];
int row_dir[4]={0,1,0,-1};
int col_dir[4] = {1,0,-1,0};
int route[21][21];
int val=0;
int maxval=0;

void dfs(int i , int j,int dist) {
    maxval=max(maxval,dist);
    for (int k=0; k<4; k++) {
        int next_row = i+row_dir[k];
        int next_col = j+col_dir[k];
        if (0<=next_row && next_row<R && 0<=next_col && next_col<C) {
            if (check_arr[arr[next_row][next_col]-'A']) {continue;}
            check_arr[arr[next_row][next_col]-'A'] = 1;
            dfs(next_row,next_col,dist+1);
            check_arr[arr[next_row][next_col]-'A'] = 0;

        }
    }
}

int main() {
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < C; j++) {
            arr[i][j]=s[j];
        }
    }
    route[0][0]=1;
    check_arr[arr[0][0]-'A']=1;
    dfs(0,0,1);
    cout << maxval;
}