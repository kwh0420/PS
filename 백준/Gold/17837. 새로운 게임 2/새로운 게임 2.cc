#include <bits//stdc++.h>
using namespace std;
vector<vector<vector<int>>> matrix(12,vector<vector<int>>(12));
int arr[12][12];
int dir[11];
pair<int,int> loc[11];
int N,K;
int cnt=1;
void move(int num) {
    auto [nrow,ncol] = loc[num];
    if (dir[num]==1) {
        if (ncol+1==N || arr[nrow][ncol+1] == 2) {
            dir[num]=2;
        }
    }
    else if (dir[num]==2) {
        if (ncol-1==-1 || arr[nrow][ncol-1] == 2) {
            dir[num]=1;
        }
    }
    else if (dir[num]==3) {
        if (nrow-1==-1 || arr[nrow-1][ncol] == 2) {
            dir[num]=4;
        }
    }
    else if (dir[num]==4) {
        if (nrow+1==N || arr[nrow+1][ncol] == 2) {
            dir[num]=3;
        }
    }

    if (dir[num]==1) {
        if (ncol+1==N || arr[nrow][ncol+1] == 2) {
            return;
        }
        for (int i=0; i<matrix[nrow][ncol].size(); i++) {
            if (matrix[nrow][ncol][i]==num) {
                for (int j=i; j<matrix[nrow][ncol].size(); j음
                    matrix[nrow][ncol].pop_back();
                }
                break;
            }
        }
        ncol=ncol+1;
    }
    else if (dir[num]==2) {
        if (ncol-1==-1 || arr[nrow][ncol-1] == 2) {
            return;
        }
        for (int i=0; i<matrix[nrow][ncol].size(); i++) {
            if (matrix[nrow][ncol][i]==num) {
                for (int j=i; j<matrix[nrow][ncol].size(); j++) {
                    matrix[nrow][ncol-1].push_back(matrix[nrow][ncol][j]);
                    loc[matrix[nrow][ncol][j]]={nrow,ncol-1};

                }                int k = matrix[nrow][ncol].size();
                for (int j=i; j<k; j++) {
                    matrix[nrow][ncol].pop_back();
                }
                break;

            }
        }
        ncol=ncol-1;
    }
    else if (dir[num]==3) {
        if (nrow-1==-1 || arr[nrow-1][ncol] == 2) {
            return;
        }
        for (int i=0; i<matrix[nrow][ncol].size(); i++) {
            if (matrix[nrow][ncol][i]==num) {
                for (int j=i; j<matrix[nrow][ncol].size(); j++) {
                    matrix[nrow-1][ncol].push_back(matrix[nrow][ncol][j]);
                    loc[matrix[nrow][ncol][j]]={nrow-1,ncol};

                }                int k = matrix[nrow][ncol].size();
                for (int j=i; j<k; j++) {
                    matrix[nrow][ncol].pop_back();
                }
                break;

            }
        }
        nrow=nrow-1;
    }
    else if (dir[num]==4) {
        if (nrow+1==N || arr[nrow+1][ncol] == 2) {
            return;
        }
        for (int i=0; i<matrix[nrow][ncol].size(); i++) {
            if (matrix[nrow][ncol][i]==num) {
                for (int j=i; j<matrix[nrow][ncol].size(); j++) {
                    matrix[nrow+1][ncol].push_back(matrix[nrow][ncol][j]);
                    loc[matrix[nrow][ncol][j]]={nrow+1,ncol};

                }                int k = matrix[nrow][ncol].size();
                for (int j=i; j<k; j++) {
                    matrix[nrow][ncol].pop_back();
                }
                break;

            }
        }
        nrow=nrow+1;
    }
    if (matrix[nrow][ncol].size()>=4){cout << cnt ;exit(0);}
    if (arr[nrow][ncol]==1) {
        for (int i=0; i<matrix[nrow][ncol].size(); i++) {
            if (matrix[nrow][ncol][i]==num) {
                vector<int> v;
                for (int j=matrix[nrow][ncol].size()-1; j>=i; j--) {
                   v.push_back(matrix[nrow][ncol][j]);
                }
                for (int j=i; j<matrix[nrow][ncol].size(); j++) {
                    matrix[nrow][ncol][j]=v[j-i];
                }
                break;
            }
        }
    }

}
void printx() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cout << matrix[i][j].size() << " ";
        }
        cout << endl;
    }
    cout << "==============" << endl;
}

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i=1; i<=K; i++) {
        int r,c,d;
        cin >> r >> c >> d;
        matrix[r-1][c-1].push_back(i);
        dir[i]=d;
        loc[i]=make_pair(r-1,c-1);
    }
    for (cnt=1; cnt<1000; cnt++) {
        for (int i=1; i<=K; i++) {

            move(i);

        }
    }
    cout << -1;

}
