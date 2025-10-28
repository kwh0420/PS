#include <bits/stdc++.h>
using namespace std;
int N,M,K;
int dirofshark[402];
pair<int, int> locofshark[402];
int arr[21][21]; //상어가 남긴 향기의 번호
int timeofarr[21][21]; // 상어가 남긴 향기의 시간
 // [상어 번호][현재 방향][다음 방향들]
int dirpriority[402][4][4];
int rowdir[4] = {-1,1,0,0};
int coldir[4] = {0,0,-1,1};
#define shark1 0
#define shark2 1
#define shark3 2
#define shark4 3
#define up 0
#define right 3
#define down 1
#define left 2
void printx() {
    cout << "cur arr : \n";
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cout << arr[i][j];
        }
        cout << "\n";
    }
    cout << "cur shark loc : \n";
    for (int i=0; i<M; i++) {
            cout << locofshark[i].first << " " << locofshark[i].second << "\n";
    }
    cout << "cur shark dir : \n";
    for (int i=0; i<M; i++) {
        if (dirofshark[i]==0) { cout << "up";};
        if (dirofshark[i]==1) { cout << "down";};
        if (dirofshark[i]==2) { cout << "left";};
        if (dirofshark[i]==3) { cout << "right";};
        cout << endl;
    }
}
int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            if (arr[i][j] != 0) { locofshark[arr[i][j] - 1] = {i, j}; }
            arr[i][j] = 0;
        }
    }
    for (int i = 0; i < M; i++) {
        cin >> dirofshark[i];
        dirofshark[i]--;
    }
    for (int k = 0; k < M; k++) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++){
                cin >> dirpriority[k][i][j];
                dirpriority[k][i][j]--;
            }
        }
    }
    int cnt=0;
    while (1) {
        if (cnt>=1000){cout << -1; return 0;}
        for (int i = 0; i < M; i++) {
            if (locofshark[i].first == -1) {continue;}
            arr[locofshark[i].first][locofshark[i].second] =i+1;
            timeofarr[locofshark[i].first][locofshark[i].second] =K;
        }
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < 8; j++) {
                if (j<4) {
                    int currow = locofshark[i].first;
                    int curcol = locofshark[i].second;
                    if (currow == -1){break;}
                    int nxtdir =dirpriority[i][dirofshark[i]][j];
                    int nrow = rowdir[nxtdir] + currow ;
                    int ncol = coldir[nxtdir] + curcol ;
                    if (0>nrow || 0>ncol || nrow>=N || ncol>=N) {
                        continue;
                    }
                    if (arr[nrow][ncol]!=0){continue;}

                    else {
                        locofshark[i] = {nrow,ncol};
                        dirofshark[i] = nxtdir;
                        break;
                    }
                }
                else if (j>=4) {
                    int currow = locofshark[i].first;
                    int curcol = locofshark[i].second;
                    int nxtdir =dirpriority[i][dirofshark[i]][j-4];
                    int nrow = rowdir[nxtdir] + currow ;
                    int ncol = coldir[nxtdir] + curcol ;
                    if (0>nrow || 0>ncol || nrow>=N || ncol>=N) {
                        continue;
                    }
                    else {
                        if (arr[nrow][ncol]== i+1) {
                            locofshark[i] = {nrow,ncol};
                            dirofshark[i] = nxtdir;
                            break;
                        }
                    }
                }
            }
        }
        cnt++;
        for (int i=0; i<M; i++) {
            if (locofshark[i].first==-1){continue;}
            for (int j=i+1; j<M; j++) {
                if (locofshark[i].first==locofshark[j].first && locofshark[i].second==locofshark[j].second) {
                    locofshark[j]={-1,-1};
                    arr[locofshark[j].first][locofshark[j].second]=0;
                }
            }
        }
        for (int i = 1; i < M; i++) {
            if (locofshark[i].first!=-1){break;}
            if (i==M-1){cout << cnt ; exit(0);}
        }
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if (timeofarr[i][j]>0){timeofarr[i][j]--;}
                if (timeofarr[i][j]==0){arr[i][j]=0;}
            }
        }
    }
}
