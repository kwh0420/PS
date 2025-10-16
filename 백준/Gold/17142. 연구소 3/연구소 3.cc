#include <bits/stdc++.h>
using namespace std;
int arr[52][52];
int N,M;
int result=99999;

int dist[52][52];
int cnt=0;

int row_dir[4]={0,1,0,-1};

int col_dir[4]={1,0,-1,0};

int arr2[11];

vector<pair<int,int>>v;
int check(){
    int maxval=0;

    for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
        if (arr[i][j]==0)
            maxval = max(maxval,dist[i][j]);
        if (dist[i][j]==-1 && arr[i][j]==0) {
            return 0;
        }
    }
}
    result = min(maxval,result);
    return 1;
}

int main() {
    cin>>N>>M;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N; j++) {
            cin >> arr[i][j];
            if (arr[i][j]==2) {
                v.emplace_back(i,j);
                cnt++;
            }
        }
    }
    for(int i=cnt-1;i>=cnt-M;i--) {arr2[i]=1;}

    do {
        queue<tuple<int,int,int>> q;
        vector<int> vv;
        for (int i=0;i<N;i++) {
            for (int j=0;j<N;j++) {
                dist[i][j]=-1;
            }
        }
        for (int i=0; i<cnt; i++) {
            if (arr2[i]==1) {
                q.push({v[i].first,v[i].second,0});
                dist[v[i].first][v[i].second]=0;
            }
        }
        while (!q.empty()) {
            auto [cur_row,cur_col,cur_time]=q.front();
            q.pop();
            for (int i=0; i<4; i++) {
                int nrow = cur_row + row_dir[i];
                int ncol = cur_col + col_dir[i];
                int ntime= cur_time+1;
                if (0<=nrow && 0<=ncol && nrow<N && ncol<N) {
                    if (arr[nrow][ncol]==1) {
                        continue;
                    }
                    else if (dist[nrow][ncol]==-1) {
                        dist[nrow][ncol]=dist[cur_row][cur_col]+1;
                        q.push({nrow,ncol,ntime});
                    }
                }
            }
        }
        if (check()) {

        }
    }while (next_permutation(arr2,arr2+cnt));
    if (result==99999) {
        cout <<-1;
        return 0;
    }
    cout << result;


}