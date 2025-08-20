#include <bits/stdc++.h>
using namespace std;
int arr[505][505];
int result[505][505];
int row_dir[4]={0,1,0,-1};
int col_dir[4]={1,0,-1,0};
int n;

int go(int row, int col) {
    if (result[row][col] != -1) {
        return result[row][col];
    }
    result[row][col] = 1;
    for (int i=0; i<4; i++) {
        int nrow=row+row_dir[i];
        int ncol=col+col_dir[i];
        if (!(0<=nrow&&nrow<n && 0<=ncol&&ncol<n) || arr[row][col]>=arr[nrow][ncol]) {continue;}
        result[row][col]=max(result[row][col],go(nrow,ncol)+1);
    }
    return result[row][col];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>arr[i][j];
            result[i][j]=-1;
        }
    }
    int mx=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            mx=max(mx,go(i,j));
        }
    }
    cout << mx << "\n";
}