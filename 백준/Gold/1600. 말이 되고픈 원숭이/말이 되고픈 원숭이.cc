#include <bits/stdc++.h>
using namespace std;
int map_arr[202][202];
int row_dir[12]={0,0,1,-1,-1,1,-2,2,-1,1,-2,2};
int col_dir[12]={1,-1,0,0,2,2,1,1,-2,-2,-1,-1};
int k=0;
int visited[30][202][202];
int col_limit,row_limit;
#define row first.first
#define col first.second
#define jump second.first
#define route second.second
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> k;
    cin >> col_limit >> row_limit;
    for(int i=0;i<row_limit;i++) {
        for(int j=0;j<col_limit;j++) {
            cin >> map_arr[i][j];
        }
    }
    queue<pair<pair<int,int>,pair<int,int>>> q;
    q.push({{0,0},{k,0}});
    visited[k][0][0]=1;
    while(!q.empty()) {
        pair<pair<int,int>,pair<int,int>> p = q.front();
        q.pop();
        if (p.row == row_limit-1 && p.col == col_limit-1) {cout << p.route; return 0;}
        for(int i=0;i<12;i++) {
            int nrow = p.row + row_dir[i];
            int ncol = p.col + col_dir[i];
            int nroute = p.route + 1;
            int njump=0;
            if (i>3){njump=p.jump-1;}
            else {njump=p.jump;}
            if (0<=nrow&&nrow<row_limit&&0<=ncol&&ncol<col_limit&&0<=njump && map_arr[nrow][ncol]!=1&&visited[njump][nrow][ncol]==0) {

                q.push({{nrow,ncol},{njump,nroute}});
                visited[njump][nrow][ncol]=1;
            }
        }
    }
    cout <<-1;


}