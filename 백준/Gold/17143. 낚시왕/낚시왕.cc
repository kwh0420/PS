#include<bits/stdc++.h>
using namespace std;
int arr[102][102];
int temp[102][102];
int sizeofshark[10002];
int speedofshark[10002];
int dirofshark[10002];
int r, c,m;
int cnt;

void move(int row, int col, int s, int dir) {
    int numofshark = arr[row][col];
    while (s != 0) {
        if (dir == 1) {
            if (row - s < 0) {
                dir = 2;
                s -= row;
                row = 0;

            } else {
                row -= s;
                s = 0;
            }
        } else if (dir == 2) {
            if (row + s > r-1) { // 끝 인덱스는 r이 아닌 r-1로 해야함
                dir = 1;
                s -= r - 1 - row;
                row = r - 1;

            } else {
                row += s;
                s = 0;
            }
        }
        else if (dir == 3) {
            if (col + s > c-1) {
                dir = 4;
                s -= c - 1 - col;
                col = c - 1;

            } else {
                col += s;
                s = 0;
            }
        }
        else if (dir == 4) {
            if (col - s < 0) {
                dir = 3;
                s -= col;
                col = 0;

            } else {
                col -= s;
                s = 0;
            }
        }
    }
    dirofshark[numofshark] = dir;
    if (temp[row][col]) {
        if (sizeofshark[temp[row][col]] < sizeofshark[numofshark]) {
            temp[row][col] = numofshark;
        }
    } else
        temp[row][col] = numofshark;
}
void hunt(int col) {
    for (int i = 0; i < r; i++) {
        if (arr[i][col]) {
            cnt+=sizeofshark[arr[i][col]];
            arr[i][col]=0;
            break;
        }
    }
}
void printx() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << arr[i][j] <<" ";
        }
        cout << endl;
    }
    cout << "-----------------------------\n";
}
void inst() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            arr[i][j]=temp[i][j];
            temp[i][j]=0;
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c>>m;
    for (int i=0; i<m; i++) {
        int R,C,S,D,Z;
        cin >> R >> C >> S >> D >> Z;
        arr[R-1][C-1] = i+1;
        speedofshark[i+1]=S;
        dirofshark[i+1]=D;
        sizeofshark[i+1]=Z;
    }
    for (int i=0; i<c; i++) {
        hunt(i);
        // 변수 이름을 k와 l (또는 k, j) 등으로 변경
        for (int k=0; k<r; k++) {
            for (int j=0; j<c; j++) {
                if (arr[k][j])
                    move(k, j, speedofshark[arr[k][j]], dirofshark[arr[k][j]]);
            }
        }
        inst();
        //printx();
    }
    cout << cnt;

}
