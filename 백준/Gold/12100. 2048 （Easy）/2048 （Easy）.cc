#include <bits/stdc++.h>
using namespace std;

int N;
int row_dir[4]={-1,0,1,0};   // 위(0), 오른쪽(1), 아래(2), 왼쪽(3)
int col_dir[4]={0,1,0,-1};
int visited[21][21];          // 이번 이동에서 이미 합쳐진 블록 체크용
vector<vector<int>> arr(21,vector<int>(21,0));  // 게임판 상태 저장

// [수정 포인트 1] 이전 상태를 복사하는 함수
vector<vector<int>> ready() {
    vector<vector<int>> before_arr(21,vector<int>(21,0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            before_arr[i][j] = arr[i][j];
        }
    }
    return before_arr;
}

// [수정 포인트 2] 백트래킹 후 상태 복구 함수
void clear(vector<vector<int>> &before_arr) {
    arr=before_arr;
}

// 핵심 합치기/이동 처리 함수
void bfs_sub(int row,int col, int mode) {
    while (1) {
        int nrow = row+row_dir[mode];
        int ncol = col+col_dir[mode];

        if (!(0<=nrow && 0<=ncol && nrow<N && ncol<N)) {
            break;   // 경계 밖이면 중단
        }
        else if (arr[nrow][ncol]==0) { [수정 포인트 6] 2번 조건과 3번 조건의 순서가 달라지면 안됨
            // [중요] 빈 칸이면 현재 칸 이동 (밀기)
            arr[nrow][ncol]=arr[row][col];
            arr[row][col]=0;
        }
        else if (arr[nrow][ncol]==arr[row][col]) { [수정 포인트 6] 2번 조건과 3번 조건의 순서가 달라지면 안됨
            // [수정 포인트 3] 같은 숫자가 만나면 합치기
            // 단, 이번 턴에 합친 적 없으면만
            if (!visited[nrow][ncol]) {
                arr[nrow][ncol] =arr[row][col]*2;
                arr[row][col]=0;
                visited[nrow][ncol]=1; // 합친 기록
            }
            break; // 합친 후 이동 끝
        }
        else {
            break; // 다른 숫자 만나면 이동 끝
        }
        row=nrow;
        col=ncol;
    }
}

// 전체 보드에 대해 이동 수행하는 함수
void bfs(int mode) {
    // [수정 포인트 4] 이동 방향에 따라 탐색 순서가 달라야 함
    // 위(0), 왼쪽(3) 방향은 앞부터
    if (mode==0||mode==3) {
        for (int i=0; i<N;i++) {
            for (int j=0; j<N; j++) {
                bfs_sub(i,j,mode);
            }
        }
    }
    // 오른쪽(1), 아래(2) 방향은 뒤부터
    else if (mode==1||mode==2) {
        for (int i=N-1; i>=0;i--) {
            for (int j=N-1; j>=0;j--) {
                bfs_sub(i,j,mode);
            }
        }
    }
    // [수정 포인트 5] 한 번의 이동 끝난 후 visited 초기화 필수
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            visited[i][j]=0;
        }
    }
}

// 현재 보드에서 최대값 리턴
int check() {
    int maxvalue=0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            maxvalue=max(maxvalue, arr[i][j]);
        }
    }
    return maxvalue;
}

int result=0;
int maxval=0;

// 최대 5번 이동하며 최대 블록 찾기 재귀 함수
void func(int n) {
    if (n==5) {
        result = check();
        maxval = max(maxval, result);
    }
    else {
        vector<vector<int>>before(21,vector<int>(21,0));
        before= ready();  // [수정 포인트 1]

        for (int i=0; i<4; i++) {  // 4방향 모두 시도
            bfs(i);                // 이동 실행
            func(n+1);             // 재귀 호출
            clear(before);         // 상태 복구 [수정 포인트 2]
        }
    }
}

int main() {
    cin >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> arr[i][j];
        }
    }
    func(0);
    cout << maxval << endl;
}
