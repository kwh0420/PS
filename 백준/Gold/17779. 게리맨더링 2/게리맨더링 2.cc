#include <bits/stdc++.h>
using namespace std;
int arr[25][25];
int temp[25][25];
int N;
int row_dir[4] = {0,1,0,-1};
int col_dir[4] = {1,0,-1,0};
int maxresult=1e9;
void func5(int x,int y, int d1, int d2) {
    int vis[N][N]={0};
    queue<pair<int,int> > q;
    q.push(make_pair(x,y));
    temp[x][y]=5;
    vis[x][y]=1;
    while(!q.empty()) {
        pair<int,int> p = q.front();
        q.pop();
        for(int i=0;i<4;i++) {
            int nrow = p.first + row_dir[i];
            int ncol = p.second + col_dir[i];
            if (0<=nrow && nrow<N && 0<=ncol && ncol<N) {
                if (vis[nrow][ncol]){continue;}
                if (temp[nrow][ncol] == 0|| temp[nrow][ncol] == 5) {
                    temp[nrow][ncol]=5;
                    q.push(make_pair(nrow,ncol));
                    vis[nrow][ncol]=1;
                }
            }
        }
    }
}
void func1(int x,int y, int d1, int d2) {
    queue<pair<int,int> > q;
    q.push(make_pair(0,0));
    temp[0][0]=1;
    while(!q.empty()) {
        pair<int,int> p = q.front();
        q.pop();
        for(int i=0;i<4;i++) {
            int nrow = p.first + row_dir[i];
            int ncol = p.second + col_dir[i];
            if (0<=nrow && nrow<x+d1 && 0<=ncol && ncol<=y) {
                if (temp[nrow][ncol] == 0) {
                    temp[nrow][ncol]=1;
                    q.push(make_pair(nrow,ncol));
                }
            }
        }
    }
}
void func2(int x,int y, int d1, int d2) {
    queue<pair<int,int> > q;
    q.push(make_pair(0,N-1));
    temp[0][N-1]=2;
    while(!q.empty()) {
        pair<int,int> p = q.front();
        q.pop();
        for(int i=0;i<4;i++) {
            int nrow = p.first + row_dir[i];
            int ncol = p.second + col_dir[i];
            if (0<=nrow && nrow<=x+d2 && y<ncol && ncol<N) {
                if (temp[nrow][ncol] == 0) {
                    temp[nrow][ncol]=2;
                    q.push(make_pair(nrow,ncol));
                }
            }
        }
    }
}
void func3(int x,int y, int d1, int d2) {
    queue<pair<int,int> > q;
    q.push(make_pair(N-1,0));
    temp[N-1][0]=3;
    while(!q.empty()) {
        pair<int,int> p = q.front();
        q.pop();
        for(int i=0;i<4;i++) {
            int nrow = p.first + row_dir[i];
            int ncol = p.second + col_dir[i];
            if (x+d1<=nrow && nrow<N && 0<=ncol && ncol<y-d1+d2) {
                if (temp[nrow][ncol] == 0) {
                    temp[nrow][ncol]=3;
                    q.push(make_pair(nrow,ncol));
                }
            }
        }
    }
}
void func4(int x,int y, int d1, int d2) {
    queue<pair<int,int> > q;
    q.push(make_pair(N-1,N-1));
    temp[N-1][N-1]=4;
    while(!q.empty()) {
        pair<int,int> p = q.front();
        q.pop();
        for(int i=0;i<4;i++) {
            int nrow = p.first + row_dir[i];
            int ncol = p.second + col_dir[i];
            if (x+d2<nrow && nrow<N && y-d1+d2<=ncol && ncol<N) {
                if (temp[nrow][ncol] == 0) {
                    temp[nrow][ncol]=4;
                    q.push(make_pair(nrow,ncol));
                }
            }
        }
    }
}
void printx() {
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cout << temp[i][j] << " ";
        }
        cout << endl;
    }
    cout << "------------------------------------\n";
}
void era() {
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            temp[i][j]=0;
        }
    }
}
void cal() {
    int calcal[6]={0};
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            calcal[temp[i][j]]+=arr[i][j];
        }
    }
    int minval=1e9;
    int maxval=0;
    for (int i=1; i<=5; i++) {
        minval  = min(minval, calcal[i]);
        maxval  = max(maxval, calcal[i]);
    }
    maxresult = min(maxval-minval, maxresult);
}
void realfunc(int x, int y, int d1, int d2) {
    if (x+d1+d2>=N) return;
    if (y-d1<0) return;
    if (y+d2>=N) return;

    for (int i=0; i<=d1; i++) {
        temp[x+i][y-i]=5;
    }
    for (int i=0; i<=d2 ; i++) {
        temp[x+i][y+i]=5;
    }
    for (int i=0; i<=d2; i++) {
        temp[x+d1+i][y-d1+i]=5;
    }

    for (int i=0; i<=d1; i++) {
        temp[x+d2+i][y+d2-i]=5;
    }

    //printx();
    func1(x,y,d1,d2);
    //printx();
    func2(x,y,d1,d2);
    //printx();
    func3(x,y,d1,d2);
    //printx();
    func4(x,y,d1,d2);
    func5(x,y,d1,d2);


  //  printx();
    cal();
    era();

}
int main() {
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            for (int k=1;k<N;k++) {
                for (int l=1;l<N;l++) {
                    realfunc(i,j,k,l);
                }
            }
        }
    }
    cout << maxresult;
}
