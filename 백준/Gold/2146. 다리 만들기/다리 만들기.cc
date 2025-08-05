#include <bits/stdc++.h>
using namespace std;
int map_arr[102][102];
int visited[102][102];
int route[102][102];
#define row first
#define col second
int cor_dir[4]={-1,1,0,0};
int row_dir[4]={0,0,1,-1};


ostream operator<<(const ostream & lhs, const __gnu_cxx::__alloc_traits<allocator<pair<pair<int, int>, int>>>::value_type::first_type & rhs);

int main() {
    int N;
    cin>>N;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin>>map_arr[i][j];
        }
    }
    int num=1;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if (visited[i][j] || map_arr[i][j]==0) {
                continue;
            }
            queue<pair<int,int> > q;
            q.push({i,j});
            map_arr[i][j]=num;
            visited[i][j]=1;

            while(!q.empty()) {
                pair<int,int> cur=q.front();
                q.pop();
                for (int k=0;k<4;k++) {
                    int nrow = cur.row+row_dir[k];
                    int ncol = cur.col+cor_dir[k];
                    if (0<=nrow && nrow<N && 0<=ncol && ncol<N && map_arr[nrow][ncol]==1 && visited[nrow][ncol]==0) {
                        q.push({nrow,ncol});
                        map_arr[nrow][ncol]=num;
                        visited[nrow][ncol]=1;
                    }
                }
            }
            num++;
        }
    }
    for (int i=0; i<N;i++) {
        for (int j=0; j<N;j++) {
            visited[i][j]=0;
        }
    }

    for (int i=0; i<N;i++) {
        for (int j=0; j<N;j++) {
            visited[i][j]=0;
        }
    }
    int min=999999999;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if (map_arr[i][j] ==0 ) {
                continue;
            }
            int cur_num = map_arr[i][j];
            queue<pair<pair<int,int>, int>> q;
            q.push({{i,j},0});
            visited[i][j]=1;
            while(!q.empty()) {
                int mode =0;
                pair<pair<int,int>,int> cur=q.front();
                q.pop();
                for (int k=0;k<4;k++) {
                    int nrow = cur.first.row+row_dir[k];
                    int ncol = cur.first.col+cor_dir[k];
                    if (0<=nrow && nrow<N && 0<=ncol && ncol<N && visited[nrow][ncol]==0) {
                        if (map_arr[nrow][ncol]==cur_num) {
                            visited[nrow][ncol]=1;
                            continue;
                        }
                        else if (map_arr[nrow][ncol]!=0) {
                            if (cur.second<min) {
                                min=cur.second;
                                mode=1;
                            }
                        }
                        else if (map_arr[nrow][ncol]==0) {
                            q.push({{nrow,ncol},cur.second+1});
                            visited[nrow][ncol]=1;
                        }
                    }
                }
                if (mode==1){break;};
            }
            for (int i=0; i<N;i++) {
                for (int j=0; j<N;j++) {
                    visited[i][j]=0;
                }
            }
        }
    }
    cout << min;
}
