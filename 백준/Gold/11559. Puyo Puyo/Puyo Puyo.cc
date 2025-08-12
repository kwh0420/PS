#include <bits/stdc++.h>
using namespace std;
int arr[12][6];
int vis[12][6];
#define R 1
#define G 2
#define B 3
#define P 4
#define Y 5
#define row first
#define col second
int row_dir[4]={0,1,0,-1};
int col_dir[4]={1,0,-1,0};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int result=0;
    for (int i = 0; i < 12; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 6; j++) {
            if (s[j]=='.')
                arr[i][j]=0;
            else if (s[j]=='R')
                arr[i][j]=1;
            else if (s[j]=='G')
                arr[i][j]=2;
            else if (s[j]=='B')
                arr[i][j]=3;
            else if (s[j]=='P')
                arr[i][j]=4;
            else if (s[j]=='Y')
                arr[i][j]=5;
        }
    }
    while (1){
    int pang=0;
    for (int i=0; i<12; i++) {
        for (int j=0; j<6; j++) {
            vis[i][j]=0;
        }
    }
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            if (arr[i][j]==0 || vis[i][j]==1) {
                continue;
            }
            queue<pair<int, int>> q;
            vector<pair<int, int>> check;
            int cnt=0;
            q.push(make_pair(i, j));
            vis[i][j]=1;
            check.push_back(make_pair(i, j));
            cnt++;
            int color= arr[i][j];
            while (!q.empty()) {
                pair<int, int> p = q.front();
                q.pop();
                for (int i=0; i<4; i++) {
                    int nrow = p.row+ row_dir[i];
                    int ncol = p.col+ col_dir[i];
                    if (0<=nrow && nrow<12 && 0<=ncol && ncol<6&&vis[nrow][ncol]==0 && color == arr[nrow][ncol]) {
                            vis[nrow][ncol]=1;
                            q.push(make_pair(nrow, ncol));
                            cnt++;
                            check.push_back(make_pair(nrow, ncol));
                    }
                }
            }

            if (cnt >=4) {
                for (auto i : check) {
                    arr[i.row][i.col]=0;
                }
                pang ++;
            }
        }
    }
    for (int j=0; j<6; j++) {
        int idx=11;
        int tilt[12]={0};
        for (int i=11; i>=0; i--) {
            if (arr[i][j]==0) {
                continue;
            }
            if (tilt[idx]==0) {
                tilt[idx]=arr[i][j];
            }
            else {
                tilt[--idx]=arr[i][j];
            }
        }
        for (int i=0; i<12; i++) {
            arr[i][j]=tilt[i];
        }
    }

    if (pang>0) {
        result++;
    }
    else {
        break;
    }
}
    cout << result;
}
