#include <bits/stdc++.h>
using namespace std;
int row_dir[4]={0,1,0,-1};
int col_dir[4]={1,0,-1,0};
int N,L,R;
int arr[52][52];
int visited[52][52];
vector<pair<int,int> > path;
int ccnt=0;
int bfs(int i,int j) {
    int result=0;
    visited[i][j]=1;
    queue<pair<int,int> > q;
    q.push(make_pair(i,j));
    while(!q.empty()) {
        pair<int,int> cur=q.front();
        result += arr[cur.first][cur.second];
        path.push_back(make_pair(cur.first,cur.second));
        q.pop();
        for(int k=0;k<4;k++) {
            int ni=cur.first+row_dir[k];
            int nj=cur.second+col_dir[k];
            if (!(0<=ni && ni<N && 0<=nj && nj<N)) {continue;}
            int n1=abs(arr[ni][nj]-arr[cur.first][cur.second]);
            if(L<=n1 && n1 <=R&& !visited[ni][nj]) {
                ccnt++;
                visited[ni][nj]=1;
                q.push(make_pair(ni,nj));
            }
        }
    }
    return result;
}
int main() {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> L >> R;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N; j++) {
            cin >> arr[i][j];
        }
    }
    int ans=0;
    while (1) {
        ccnt=0;
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                if (visited[i][j]){continue;}
                int result=0;
                result+=bfs(i,j);
                for (auto [x,y]:path) {
                    arr[x][y]=result/path.size();
                }
                path.clear();

            }
        }
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                visited[i][j]=0;
            }
        }
        if (ccnt==0){break;}
        else { ans++;}
    }
    cout << ans;

}