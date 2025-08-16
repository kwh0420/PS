#include <bits/stdc++.h>
using namespace std;
int N,L;
int arr[101][101];
int vis[101];
void rotate() {
    int temp[101][101];
    for (int i=0 ; i<N ; i++) {
        for (int j=0; j<N ; j++) {
            temp[j][i] = arr[N-1-i][j];
        }
    }
    for (int i=0 ; i<N ; i++) {
        for (int j=0 ; j<N ; j++) {
            arr[i][j] = temp[i][j];
        }
    }
}
int check (int depth, int j,int mode) {
    if (mode==1) {
        int k= j-L;
        if (!(0<=k && k<N)) {
            return 0;
        }
        int cond=arr[depth][k];
        for (int i=k; i<j ; i++) {
            if (vis[i]==1) {
                return 0;
            }
            if (arr[depth][i]!=cond) {
                return 0;
            }
        }
        return 1;
    }
    else if (mode==-1) {
        int k= j+L -1;
        if (!(0<=k && k<N)) {
            return 0;
        }
        int cond=arr[depth][k];
        for (int i=j; i<k ; i++) {
            if (vis[i]==1) { //경사로를 같은 곳에 2번 놓지 않도록 vis 배열을 사용함. 해답지엔 cnt를 이용해서, cnt가 L이상이 아닐경우 경사로를 못놓는 방식으로 구현. 
                return 0;
            }
            if (arr[depth][i]!=cond) {
                return 0;
            }
        }
        return 1;
    }
}
int func(int depth) {
    for (int i=0; i<N; i++) {
        vis[i]=0;
    }
    for (int j=1 ; j<N ; j++) {
            int net_minus= arr[depth][j]-arr[depth][j-1];
            if (net_minus==0) {
                continue;
            }
            else if (net_minus==-1 || net_minus==1) {
                if (check(depth,j,net_minus)) {
                    if (net_minus==1) {
                        for (int i=j-L ; i<j ; i++) {
                            vis[i]=1;
                        }
                        continue;
                    }
                    else if (net_minus==-1) {
                        for (int i=j ; i<j+L ; i++) {
                            vis[i]=1;
                        }

                    }
                    continue;
                }
                else {
                    return 0;
                }
            }
            else {
                return 0;

            }
        }

    return 1;
    }

int main() {
    cin >> N >> L;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >>arr[i][j];
        }
    }
    int sum=0;
    for (int i=0; i<N; i++) {
        sum+=func(i);
    }
    rotate();
    for (int i=0; i<N; i++) {
        sum+=func(i);
    }
    cout << sum ;
}

