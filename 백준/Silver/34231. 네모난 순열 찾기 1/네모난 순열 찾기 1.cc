#include <bits/stdc++.h>
using namespace std;
int N;
int arr[16][16];
int check(int i, int j, int n ,int m) {
    priority_queue<int,vector<int>,greater<int>>q;
    for (int a=i; a<=n; a++) {
        for (int b=j; b<=m; b++) {
            q.push(arr[a][b]);
        }
    }
    int r=1;
    while (!q.empty()) {
        int val=q.top();
        if (r!=val) {
            return 0;
        }
        q.pop();
         r++;
    }
    return 1;

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >>N;
    int result=0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int n = i; n < N; n++) {
                for (int m = j; m < N; m++) {
                    result+=check(i,j,n,m);
                }
            }
        }
    }
    cout << result;
}