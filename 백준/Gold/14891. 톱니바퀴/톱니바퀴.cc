#include <bits/stdc++.h>
using namespace std;
int arr[4][8];
int rotate_index[4];

// 톱니 회전 함수
// mode: 1이면 시계방향, -1이면 반시계방향
// (i+mode+8)%8 → 음수 인덱스 방지용
void rotate(int top,int mode) {
    int temp[8]={};
    for (int i=0;i<8; i++) {
        temp[(i+mode+8)%8]=arr[top][i];
    }
    for (int i=0;i<8;i++) {
        arr[top][i]=temp[i];
    }
}

/*
    [삽질 기록]
    1차: 처음에는 check() 함수로 인접 톱니 비교를 했는데, 맞물리는 인덱스를 잘못 선택(1,5 비교).
         → 톱니 맞물림은 왼쪽의 2번 인덱스와 오른쪽의 6번 인덱스여야 함.
    2차: 전파할 때 바로바로 rotate()를 호출함 → 한 톱니가 회전하면서 옆 톱니 비교 기준이 변해버림 → 전파 로직 꼬임.
         → 해결: 회전 방향(dirs[])을 먼저 전부 계산한 후, 한 번에 rotate() 호출.
    3차: while 루프 조건에서 idx 범위를 잘못 잡아 무한 루프 발생.
         → 해결: 오른쪽 전파는 idx<3, 왼쪽 전파는 idx>0 조건으로 수정.
    4차: 시계/반시계 방향 전파 부호 반대로 설정 실수.
         → 해결: dirs[idx+1] = -dirs[idx], dirs[idx-1] = -dirs[idx]로 일관성 유지.
*/

int main() {
    // 입력: 4개의 톱니 상태
    for (int i=0;i<4;i++) {
        string s;
        cin>>s;
        for (int j=0;j<8;j++) {
            arr[i][j]=s[j]-'0';
        }
    }

    int n; // 회전 횟수
    cin>>n;

    for (int i=0;i<n;i++) {
        int n1,n2;
        cin>>n1>>n2; // 톱니 번호, 회전 방향
        n1--;

        int dirs[4]={0}; // 각 톱니의 회전 방향 저장
        dirs[n1]=n2;

        // 오른쪽 전파: 현재 톱니의 2번과 오른쪽 톱니의 6번 비교
        int idx=n1;
        while (idx<3 && arr[idx][2] != arr[idx+1][6]) {
            dirs[idx+1]=dirs[idx]*(-1);
            idx++;
        }

        // 왼쪽 전파: 현재 톱니의 6번과 왼쪽 톱니의 2번 비교
        idx=n1;
        while (idx>0 && arr[idx][6] != arr[idx-1][2]) {
            dirs[idx-1]=dirs[idx]*(-1);
            idx--;
        }

        // 전파 방향 계산 끝 → 이제 한 번에 회전 실행
        for (int i=0; i<4; i++) {
            rotate(i,dirs[i]);
        }
    }

    // 점수 계산: 각 톱니의 0번 위치 값 × 가중치
    cout << arr[0][0] + arr[1][0]*2 + arr[2][0]*4 + arr[3][0]*8;
}
