#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> v(52,vector<int>(52));
int T;
int N,M;
void rotate(int num,int dir,int K) {
    vector<int> temp(M);
    int flag;
    if (dir==0) flag=1;
    else flag=-1;
    for (int i=0;i<M;i++) {
        temp[(i+flag*K+M)%M]=v[num][i];
    }
    swap(v[num],temp);
}
int calculate() {
    int result=1;
    vector<vector<int>> temp(52,vector<int>(52));
    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            if (v[i][j]==-1){temp[i][j]=-1; continue;}
            if (v[i][j]==v[i][(j-1+M)%M] || v[i][j]==v[i][(j+1)%M]){
                temp[i][j]=-1;
                result=0;
            }
            else if (i+1<N && v[i][j]==v[i+1][j]){
                temp[i][j]=-1;
                result=0;
            }
            else if (i-1>=0 && v[i][j]==v[i-1][j]) {
                temp[i][j]=-1;
                result=0;
            }
            else {
                temp[i][j]=v[i][j];
            }
        }
    }
    swap(temp,v);
    return result;
}
double modify() {
    double k=0;
    int total=0;
    int cnt=0;
    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            if (v[i][j]!=-1) {
                total+=v[i][j];
                cnt++;
            }
        }
    }
    k=(double)total/cnt;
    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++){
            if (v[i][j]==-1) continue;
            if (v[i][j]<k){v[i][j]+=1;}
            else if (v[i][j]>k){v[i][j]-=1;}
        }
    }
    return k;
}
void printx() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}
void answer() {
    int sumof=0;
    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            if (v[i][j]!=-1)
            sumof+=v[i][j];
        }
    }
    cout << sumof;
}
int main() {
    cin >> N >> M >> T;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> v[i][j];
        }
    }
    for (int i=0; i<T; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        for (int i=a-1; i<N; i+=a) {
            rotate(i,b,c);

        }
        if (calculate()) {
            modify();
        }
        //printx();
    }
    answer();
}