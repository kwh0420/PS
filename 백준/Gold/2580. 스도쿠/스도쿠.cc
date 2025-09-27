#include <bits/stdc++.h>
using namespace std;
int arr[9][9];
int cnt=0;
vector<pair<int,int>> v;
int row_min[9]={0,0,0,3,3,3,6,6,6};
int row_max[9]={3,3,3,6,6,6,9,9,9};
int col_max[9]={3,6,9,3,6,9,3,6,9};
int col_min[9]={0,3,6,0,3,6,0,3,6};
int check_row(int row,int col,int target) {
    for (int i = 0; i < 9; i++) {
        if (arr[row][i]==target && i!=col)return false;
    }
    return true;
}
int check_col(int row,int col,int target) {
    for (int i = 0; i < 9; i++) {
        if (arr[i][col]==target&&i!=row)return false;
    }
    return true;
}
int convertnum(int row,int col) {
    if (row<3 && col<3) {return 0;}
    if (row<3 && col<6) {return 1;}
    if (row<3 && col<9) {return 2;}
    if (row<6 && col<3) {return 3;}
    if (row<6 && col<6) {return 4;}
    if (row<6 && col<9) {return 5;}
    if (row<9 && col<3) {return 6;}
    if (row<9 && col<6) {return 7;}
    if (row<9 && col<9) {return 8;}
}
int check_99(int num,int row, int col,int target) {
    for (int i=row_min[num]; i<row_max[num]; i++) {
        for (int j=col_min[num]; j<col_max[num]; j++) {
            if (arr[i][j]==target&& i!=row && j !=col) {
                return false;
            }
        }
    }
    return true;
}
void dfs(int depth) {
    if (depth == cnt) {    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << arr[i][j] << " ";
        }
        cout <<"\n";
    }
    exit(0);}
    auto [cur_row,cur_col] = v[depth];
    int k=convertnum(cur_row,cur_col);
    for (int i=1; i<=9; i++) {
        if (!check_row(cur_row,cur_col,i)) continue;
        if (!check_col(cur_row,cur_col,i)) continue;
        if (!check_99(k,cur_row,cur_col,i)) continue;
        arr[cur_row][cur_col]=i;
        dfs(depth+1);
        arr[cur_row][cur_col]=0;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> arr[i][j];
            if (arr[i][j]==0) { v.push_back(make_pair(i,j)); }
        }
    }
    cnt = v.size();
    dfs(0);

}