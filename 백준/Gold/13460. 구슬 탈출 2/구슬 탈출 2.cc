#include <bits/stdc++.h>
using namespace std;

int N,M;
int goal_row,goal_col;
char arr[11][11];
char back_up[11][11];

// rotate 함수
void rotate(int& a,int& b) {
    char temp[11][11];
    for (int i=0; i<N ;i ++) {
        for (int j=0; j<M; j ++) {
            temp[j][N-1-i]=arr[i][j];
        }
    }
    
    int t=a; 
    a=b; 
    b=t; 

    for (int i=0; i<N; i ++) {
        for (int j=0; j<M; j ++) {
            arr[i][j]=temp[i][j]; // 이전에는 N,M 혼동으로 인덱스 벗어남
        }
    }
}

int min_val=999999;

int tilt(int mode) {
    int n=4-mode;
    int r=0;
    int b=0;

    for (int i=0; i<mode; i ++) {
        rotate(N,M);
    }

    // 구슬 이동 로직 복원
    for (int i = 1; i < N-1; i++) {
        char tilt[11]={0};
        int index=1;
        for (int j=1; j<M-1; j++) {
            if (arr[i][j]=='.'||arr[i][j]=='#'||arr[i][j]=='O') { 
                if (arr[i][j]=='#'||arr[i][j]=='O') {
                    tilt[j]=arr[i][j];
                    index=j; 
                    // #과 O 위치는 변하지 않도록 처리
                }
                continue;
            }
            else if (tilt[index]==0) {
                tilt[index]=arr[i][j];
            }
            else if (tilt[index]=='O') {
                if (arr[i][j]=='B')
                    b=1;
                else if (arr[i][j]=='R') {
                    r=1;
                }
            }
            else {
                tilt[++index]=arr[i][j];
            }

        }
        for (int j=1; j<M-1; j++) {
            if (tilt[j])
              arr[i][j]=tilt[j];
            else
                arr[i][j]='.';
        }
    }

    // tilt 함수 종료 후 배열 원래 상태로 복원 위해 rotate 다시 수행
    for (int i=0; i<n; i++){
        rotate(N,M);
        // 이전 코드에서는 rotate 후 다시 원상복구 안 해서 계속 배열 꼬임
    }

    if (r==1 && b!=1) {
        return 1;
    }
    else if (b==1) {
        return -1;
    }
    return 0;
}

// func 재귀
void func(int depth) {
    if (depth==10) { 
        // 이전에는 depth==2로 제한 → 탐색이 너무 얕아 탈출 못함
        return;
    }
    char temp[11][11];
    memcpy(temp,arr,sizeof(arr));

    for (int i=0; i<4; i++) {
        int n=tilt(i);
        if (n==1) {
            min_val=min(min_val,depth+1); 
            // 이전에는 depth 그대로 min_val 사용 → 실제 이동 횟수보다 1작게 저장됨
            memcpy(arr,temp,sizeof(temp));
            continue;
        }
        else if (n==-1) {
            memcpy(arr,temp,sizeof(temp));
            continue;
        }
        func(depth+1);
        memcpy(arr,temp,sizeof(temp));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> arr[i][j];
        }
    }

    func(0); 

    cout << ((min_val==999999)?-1:min_val); 
}
