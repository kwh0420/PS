#include <bits/stdc++.h>
using namespace std;
char arr[12][12];
unordered_map<string,int>mp;
int n,m,k;
int row_dir[8]={1,1,1,-1,-1,-1,0,0};
int col_dir[8]={1,0,-1,1,0,-1,1,-1};
string s;
void dfs(int i, int j,int depth) {
    s.push_back(arr[i][j]);
    mp[s]++;
    if (depth<4) {
        for(int k=0;k<8;k++) {
            int ni = (i+row_dir[k]+n)%n;
            int nj = (j+col_dir[k]+m)%m;
            dfs(ni,nj,depth+1);
        }
    }
    s.pop_back();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m>>k;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin>>arr[i][j];
        }
    }

    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            dfs(i,j,0);
        }
    }
    for (int i=0 ; i<k; i++) {
        string s;
        cin>>s;
        cout << mp[s] << "\n";
    }
}