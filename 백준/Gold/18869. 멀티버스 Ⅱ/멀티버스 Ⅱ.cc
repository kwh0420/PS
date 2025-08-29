#include <bits/stdc++.h>
using namespace std;
int N,M;
vector<int> uni [101];
int arr[101][10002];
int result[101][10002];
int cnt=0;
void go(int i, int j) {
    for(int k=0;k<N;k++) {
        if (result[i][k]!=result[j][k]) {
            return;
        }
    }
    cnt++;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>M>>N;

    for(int i=0;i<M; i++) {
        for(int j=0;j<N;j++) {
            cin>>arr[i][j];
            uni[i].push_back(arr[i][j]);
        }
    }
    for(int i=0;i<M;i++) {
        sort(uni[i].begin(),uni[i].end());
    }
    for(int i=0;i<M;i++) {
        uni[i].erase(unique(uni[i].begin(),uni[i].end()),uni[i].end());
    }
    for(int i=0;i<M;i++) {
        for(int j=0;j<N;j++) {
            result[i][j]=lower_bound(uni[i].begin(),uni[i].end(),arr[i][j]) - uni[i].begin();
        }
    }

    for(int i=0;i<M;i++) {
        for(int j=i+1;j<M;j++) {
            go(i,j);
        }
    }
    cout<<cnt;

}