#include <bits/stdc++.h>
using namespace std;
int v[102][102];
int tempv[102][102];
int rownum[102];
int colnum[102];
int r,c,k;
int row,col;
int nextrow,nextcol;
void R(int i) {
    int temp[102]={0};
        for (int p=0; p<col; p++) {
            temp[v[i][p]]++;
        }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for (int k=1; k<102; k++) {
        if (temp[k]>0) {
            pq.push({temp[k],k});
        }
    }
        int cnt=0;
    while (!pq.empty()) {
        tempv[i][cnt++]=pq.top().second;
        tempv[i][cnt++]=pq.top().first;
        if (cnt==100){break;}
        pq.pop();
    }
    rownum[i]=cnt;
    nextcol = max(nextcol,cnt);
}
void C(int i) {
    int temp[102]={0};
    for (int p=0; p<row; p++) {
        temp[v[p][i]]++;
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for (int k=1; k<102; k++) {
        if (temp[k]>0) {
            pq.push({temp[k],k});
        }
    }
    int cnt=0;
    while (!pq.empty()) {
        tempv[cnt++][i]=pq.top().second;
        tempv[cnt++][i]=pq.top().first;
        if (cnt==100){break;}
        pq.pop();
    }
    nextrow = max(nextrow,cnt);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>r>>c>>k;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            cin>>v[i][j];
        }
    }
    row=3;
    col=3;
    int result=0;
    while (v[r-1][c-1]!=k) {
        if (result ==100) {cout << -1;return 0;}

        if (row>=col) {
            for (int i=0; i<row; i++) {
                R(i);
            }
            col=nextcol;
            nextcol=0;
        }
        else {
            for (int j=0; j<col; j++) {
                C(j);
            }
            row=nextrow;
            nextrow=0;
        }
        for (int i=0; i<row; i++) {
            for (int j=0; j<col; j++) {
                v[i][j]=tempv[i][j];
                tempv[i][j]=0;
            }
        }
        result ++;
    }
    cout << result;
}
