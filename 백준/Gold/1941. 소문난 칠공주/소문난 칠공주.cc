#include <bits/stdc++.h>
using namespace std;
#define row first
#define col second
int test_arr[5][5];
bool visited[5][5];
int row_dir[4] = {0, 1, 0, -1};
int col_dir[4] = {1, 0, -1, 0};
int result=0;
int input_arr[5][5];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[25] = {0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    for (int i=0; i<5 ; i++) {
        string s;
        cin >>s;
        for (int j=0; j<5; j++) {
            if (s[j]=='S') {
                input_arr[i][j]=1;
            }
        }
    }
    do {
        pair<int,int> p[7];
        for (int i=0; i<7; i++) {
            p[i].row = 0;
            p[i].col = 0;
        }
        int index=0;
        for (int i = 0; i < 25; i++) {
            if (arr[i]==0) {
                test_arr[i/5][i%5]=1;
                p[index++]= {i/5,i%5};
            }
        }
        int max=0;
        for (int i=0; i<5; i++) {
            for (int j=0; j<5; j++) {
                int cnt=0;
                if (visited[i][j] || test_arr[i][j]==0){continue;}
                queue<pair<int,int> > q;
                q.push(make_pair(i,j));
                visited[i][j]=1;
                cnt ++;


                while (!q.empty()) {
                    pair<int,int> p = q.front();
                    q.pop();
                    for (int i=0; i<4; i++) {
                        int nrow = p.row+row_dir[i];
                        int ncol = p.col+col_dir[i];
                        if (0<=nrow && nrow<5 && 0<=ncol && ncol<5 && test_arr[nrow][ncol]==1 && visited[nrow][ncol]==0) {
                            q.push(make_pair(nrow,ncol));
                            visited[nrow][ncol]=1;
                            cnt ++;
                        }

                    }
                }
                if (cnt > max) {
                    max = cnt;
                }

            }
        }
        if (max == 7) {
            int check=0;
            for (auto i : p) {
                if (input_arr[i.row][i.col]==1) {
                    check++;
                }
            }
            if (check>=4) {
                result++;
            }
        }
        for (int i=0; i<5; i++) {
            for (int j=0; j<5; j++) {
                test_arr[i][j]=0;
                visited[i][j]=0;
            }
        }
    }
    while (next_permutation(arr,arr+25));
    cout << result;
}