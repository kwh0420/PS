#include <bits/stdc++.h>
#define height first
#define row second.first
#define col second.second
int arr[5][5][5];
int cube[5][5][5];
int row_dir[6]={1,-1,0,0,0,0};
int col_dir[6]={0,0,1,-1,0,0};
int height_dir[6]={0,0,0,0,1,-1};
int minval=99999999;
int ord[5]={0,1,2,3,4};
int temp[5];
int consistarr[5][5][5];
using namespace std;
int cnt=0;
void bfs() {
    if (cube[0][0][0]==0||cube[4][4][4]==0) {
        return;
    }
    queue<pair<int,pair<int,int>>> q;
    int visit[5][5][5]={0};
    int route[5][5][5]={0};
    q.push({0,{0,0}});
    visit[0][0][0]=1;

    while (!q.empty()) {
        pair<int,pair<int,int>> p = q.front();
        q.pop();
        for (int i=0; i<6; i++) {
            int nrow = p.row+row_dir[i];
            int ncol = p.col+col_dir[i];
            int nheight = p.height+height_dir[i];
            if (nrow==4 && ncol==4 && nheight==4) {
                minval=min(minval,route[p.height][p.row][p.col]+1);
                return;
            }
            if (0<=nrow&&nrow<5&&0<=ncol&&ncol<5&&0<=nheight&&nheight<5) {
                if (visit[nheight][nrow][ncol]==0) {
                    if (cube[nheight][nrow][ncol]==1) {
                        q.push({nheight,{nrow,ncol}});
                        visit[nheight][nrow][ncol]=1;
                        route[nheight][nrow][ncol]=route[p.height][p.row][p.col]+1;
                    }
                }
            }
        }
    }
}
void consist() {
    for (int i=0; i<5; i++) {
        if (temp[i]==0) {
            for (int j=0; j<5; j++) {
                for (int k=0; k<5; k++) {
                    consistarr[ord[i]][j][k]=arr[ord[i]][j][k];
                }
            }
        }
        if (temp[i]==1) {
            for (int j=0; j<5; j++) {
                for (int k=0; k<5; k++) {
                    consistarr[ord[i]][k][4-j]=arr[ord[i]][j][k];
                }
            }
        }
        if (temp[i]==2) {
            for (int j=0; j<5; j++) {
                for (int k=0; k<5; k++) {
                    consistarr[ord[i]][4-j][4-k]=arr[ord[i]][j][k];
                }
            }
        }
        if (temp[i]==3) {
            for (int j=0; j<5; j++) {
                for (int k=0; k<5; k++) {
                    consistarr[ord[i]][4-k][j]=arr[ord[i]][j][k];
                }
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i = 0; i < 5; i++) {
        for (int j=0; j<5; j++) {
            for (int k=0; k<5; k++) {
                cin >> arr[i][j][k];
            }
        }
    }
    consist();

    do {
        for (int mask = 0 ; mask < 1024; mask++) {
            int nmask=mask;
            for (int i=0; i<5; i++) {
                temp[i]=nmask%4;
                nmask/=4;
            }
            consist();
            for (int i=0; i<5; i++) {
                for (int j=0; j<5; j++) {
                    for (int z=0; z<5; z++) {
                        cube[i][j][z]=consistarr[ord[i]][j][z];
                    }
                }
            }

            bfs();
        }
    }while (next_permutation(ord,ord+5));
    cout << ((minval==99999999)?-1:minval) << endl;
}
