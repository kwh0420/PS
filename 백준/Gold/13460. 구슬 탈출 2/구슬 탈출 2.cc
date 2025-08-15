#include <bits/stdc++.h>
using namespace std;
int N,M;
int goal_row,goal_col;
char arr[11][11];
char back_up[11][11];
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
            arr[i][j]=temp[i][j];
        }
    }

    return;

}
int min_val=999999;
int tilt(int mode) {
    int n=4-mode;
    int r=0;
    int b=0;
    for (int i=0; i<mode; i ++) {
        rotate(N,M);
    }
    for (int i = 1; i < N-1; i++) {
        char tilt[11]={0};
        int index=1;
        for (int j=1; j<M-1; j++) {
            if (arr[i][j]=='.'||arr[i][j]=='#'||arr[i][j]=='O') {
                if (arr[i][j]=='#'||arr[i][j]=='O') {
                    tilt[j]=arr[i][j];
                    index=j;
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

    for (int i=0; i<n; i++){
    rotate(N,M);
    }

    if (r==1 && b!=1) {
        return 1;
    }
    else if (b==1) {
        return -1;
    }
    return 0;
}
void func(int depth) {

    if (depth==10) {
        return;
    }

    char temp[11][11];
    memcpy(temp,arr,sizeof(arr));

    for (int i=0; i<4; i++) {

        int n=tilt(i);
        if (n==1) {
            min_val=min(min_val,depth+1);
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
            if (arr[i][j]=='O') {
                goal_row=i;
                goal_col=j;
            }
        }
    }

    func(0);
    cout << ((min_val==999999)?-1:min_val);
}
