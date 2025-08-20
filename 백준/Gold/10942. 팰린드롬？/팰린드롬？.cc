#include <bits/stdc++.h>
using namespace std;
int N;
int arr[2001];
int dp[2001][2001];
void go1(int index,int range) {
    int index1=index-range;
    int index2=index+range;
    if (!(0<=index1&&index1<N)||!(0<=index2&&index2<N)){return;}

    if (arr[index1]==arr[index2]) {
        dp[index1][index2]=1;
        go1(index,range+1);
    }
}
void go2(int index,int range) {
    int index1=index-range+1;
    int index2=index+range;
    if (!(0<=index1&&index1<N)||!(0<=index2&&index2<N)){return;}

    if (arr[index1]==arr[index2]) {
        dp[index1][index2]=1;
        go2(index,range+1);
    }

    }
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> arr[i];
        dp[i][i]=1;
    }
    for (int i=0; i<N; i++) {
        go1(i,1);
        go2(i,1);
    }
    int M;
    cin >> M;
    /*for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cout << dp[i][j] << " ";
        }
        cout <<"\n";
    }*/
    for (int i=0; i<M; i++) {
        int a,b;
        cin >> a>>b;
        cout << dp[a-1][b-1] << "\n";
    }
}