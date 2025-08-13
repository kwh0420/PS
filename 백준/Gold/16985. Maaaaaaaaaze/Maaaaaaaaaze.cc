#include <bits/stdc++.h>
#define height first
#define row second.first
#define col second.second

int arr[5][5][5];      // 원본 5층 배열
int cube[5][5][5];     // BFS에 실제로 사용할 큐브
int row_dir[6]={1,-1,0,0,0,0};
int col_dir[6]={0,0,1,-1,0,0};
int height_dir[6]={0,0,0,0,1,-1};
int minval=99999999;
int ord[5]={0,1,2,3,4}; // 층 순서
int temp[5];            // 각 층 회전 정보
int consistarr[5][5][5];
using namespace std;
int cnt=0;

void bfs() {
    if (cube[0][0][0]==0||cube[4][4][4]==0) return; // 출발점/도착점 막힌 경우 바로 return
    queue<pair<int,pair<int,int>>> q;
    int visit[5][5][5]={0};
    int route[5][5][5]={0};
    q.push({0,{0,0}});
    visit[0][0][0]=1;

    while (!q.empty()) {
        pair<int,pair<int,int>> p = q.front();
        q.pop();
        for (int i=0; i<6; i++) {
            int nrow = p.row+row_dir[i];
            int ncol = p.col+col_dir[i];
            int nheight = p.height+height_dir[i];
            if (nrow==4 && ncol==4 && nheight==4) { // 도착점 도달
                minval=min(minval,route[p.height][p.row][p.col]+1);
                return;
            }
            if (0<=nrow&&nrow<5&&0<=ncol&&ncol<5&&0<=nheight&&nheight<5) {
                if (visit[nheight][nrow][ncol]==0 && cube[nheight][nrow][ncol]==1) { // 이부분에서 nheight, nrow, ncol의 순서 틀려서 엄청 헤맴
                    q.push({nheight,{nrow,ncol}});
                    visit[nheight][nrow][ncol]=1;
                    route[nheight][nrow][ncol]=route[p.height][p.row][p.col]+1;
                }
            }
        }
    }
}

void consist() {
    for (int i=0; i<5; i++) {
        // --------------------------------------------
        // 0도 , 90도, 180도, 270도 식이 완전히틀림 (90도 : i,4-j = i,j / 180도 : 4-i,4-j = i,j / 270도 : 4-i,j =i,j/)
        // --------------------------------------------
        if (temp[i]==0) { // 0도
            for (int j=0; j<5; j++)
                for (int k=0; k<5; k++)
                    consistarr[ord[i]][j][k]=arr[ord[i]][j][k]; //이부분에서 consis[i]=arr[ord[i]]이런식으로 해서 틀림
        }
        if (temp[i]==1) { // 90도
            for (int j=0; j<5; j++)
                for (int k=0; k<5; k++)
                    consistarr[ord[i]][k][4-j]=arr[ord[i]][j][k];
        }
        if (temp[i]==2) { // 180도
            for (int j=0; j<5; j++)
                for (int k=0; k<5; k++)
                    consistarr[ord[i]][4-j][4-k]=arr[ord[i]][j][k];
        }
        if (temp[i]==3) { // 270도
            for (int j=0; j<5; j++)
                for (int k=0; k<5; k++)
                    consistarr[ord[i]][4-k][j]=arr[ord[i]][j][k];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력 받기
    for (int i = 0; i < 5; i++)
        for (int j=0; j<5; j++)
            for (int k=0; k<5; k++)
                cin >> arr[i][j][k];

    consist(); // 초기 회전 배열 생성

    do {
        for (int mask = 0 ; mask < 1024; mask++) { // 4^5 가능한 회전 경우
            int nmask=mask;
            for (int i=0; i<5; i++) {
                temp[i]=nmask%4; // 각 층 회전 선택
                nmask/=4;
            }

            consist(); // --------------------------------------------
                       // 문제: consistarr에 회전 정보 반영 후
                       // cube에 적용 시 rotation index 사용 누락
                       // --------------------------------------------
            for (int i=0; i<5; i++)
                for (int j=0; j<5; j++)
                    for (int z=0; z<5; z++)
                        cube[i][j][z] = consistarr[ord[i]][j][z]; // <-- 여기가 문제
            bfs();
        }
    }while (next_permutation(ord,ord+5));

    cout << ((minval==99999999)?-1:minval) << endl;
