#include <bits/stdc++.h>
#define row first
#define col second
using namespace std;
int row_dir[8]={1,1,-1,-1,2,2,-2,-2};
int col_dir[8]={2,-2,2,-2,1,-1,1,-1};
bool visited[301][301];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int l ;
        cin>>l;
        for (int j=0; j<l; j++) {
            for (int z=0; z<l; z++) {
                visited[j][z]=false;
            }
        }
        queue<pair<pair<int,int>,int>> q;
        pair<int,int> cur;
        pair<int,int> arr;
        cin >> cur.row >> cur.col;
        q.push({{cur.row,cur.col},0});
        cin >> arr.row >> arr.col;

        while (1) {

            pair<pair<int,int>,int> p = q.front();
            if (p.first.row==arr.row && p.first.col==arr.col) {
                cout  << p.second << "\n";
                break;
            }
            q.pop();
            for (int i=0; i<8; i++) {
                int nrow = p.first.row+row_dir[i];
                int ncol = p.first.col+col_dir[i];
                if ((0<=nrow&&nrow<l)&& (0<=ncol&&ncol<l)&& visited[nrow][ncol]==false) {
                    q.push({{nrow,ncol},p.second+1});
                    visited[nrow][ncol]=true;

                }
            }
        }
    }
}