#include <bits/stdc++.h>
using namespace std;
int maxresult = 0;
int result = 0;
int numofish[4][4];
int dirofish[4][4];
pair<int, int> locofshark;
int row_dir[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int col_dir[8] = {0, -1, -1, -1, 0, 1, 1, 1};
pair<int,int> findloc(int num) {
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            if (numofish[i][j] == num) {
                return make_pair(i, j);
            }
        }
    }
    return {-1,-1};
}
void printx() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << numofish[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << dirofish[i][j] << " ";
        }
        cout << endl;
    }
    cout << "------------\n";
}

void shift(int i, int j) {
    int num = numofish[i][j];
    if (num == 0 || num == -1) { return; }
    for (int k = 0; k < 8; k++) {
        int cur_dir = dirofish[i][j];

        int nrow = i + row_dir[cur_dir];
        int ncol = j + col_dir[cur_dir];
        if (0 > nrow || 0 > ncol || nrow >= 4 || ncol >= 4 || numofish[nrow][ncol] == -1) {
            dirofish[i][j] = (dirofish[i][j] + 1) % 8;
            continue;
        } else {
            swap(numofish[nrow][ncol], numofish[i][j]);
            swap(dirofish[nrow][ncol], dirofish[i][j]);
            return;
        }
    }
    return;
}

void func(int depth) {
    int temp[4][4]={0};
    int temp2[4][4]={0};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            temp[i][j] = dirofish[i][j];
            temp2[i][j] = numofish[i][j];
        }
    }
    for (int i=1; i<=16; i++) {
        auto [row,col] = findloc(i);
        if (row==-1 || col==-1) { continue; }
        shift(row, col);
    }
    //printx();

    int cur_row = locofshark.first;
    int cur_col = locofshark.second;
    for (int i = 1; i < 4; i++) {
        int nrow = row_dir[dirofish[cur_row][cur_col]] * i + cur_row;
        int ncol = col_dir[dirofish[cur_row][cur_col]] * i + cur_col;
        if (0 > nrow || 0 > ncol || nrow >= 4 || ncol >= 4) { continue; }
        if (numofish[nrow][ncol] == 0) { continue; }
        int t = numofish[nrow][ncol];
        int p = dirofish[cur_row][cur_col];
        numofish[nrow][ncol] = -1;
        dirofish[cur_row][cur_col] = 0;
        numofish[cur_row][cur_col] = 0;
        locofshark= {nrow, ncol};
        result += t;
        func(depth + 1);
        numofish[nrow][ncol] = t; // 실수 1 백트래킹에서 이동한 곳에 존재하는 물고기, 이동한 곳의 물고기의 방향, 원래 위치의 물고기, 원래 위치의 방향 총 4가지를 복원해주어야해서 매우 까다롭다 느껴짐
        dirofish[cur_row][cur_col] = p;
        numofish[cur_row][cur_col] = -1;
        locofshark = {cur_row, cur_col};
        result -=t;
    }
    maxresult = max(result, maxresult);
    swap(temp,dirofish);// 실수 2 물고기가 이동하는데 이것도 백트래킹 해주어야한다는 사실을 알지 못함
    swap(temp2,numofish);
}

int main() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> numofish[i][j] >> dirofish[i][j];
            dirofish[i][j]--; // 실수 3, 물고기의 방향을 0-based로 해야할지 몰랐음.
            if (i == 0 && j == 0) {
                result += numofish[i][j];
                numofish[i][j] = -1;
            }
        }
    }
    locofshark = {0, 0};
    func(0);
    cout << maxresult ;
}

