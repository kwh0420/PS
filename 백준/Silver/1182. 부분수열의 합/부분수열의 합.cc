#include <bits/stdc++.h>
using namespace std;
int visited_col[21];
int result[21];
int arr[21];
int N;
int S;
int cnt=0;
void queen(int row,int sum) {
    if (row == N) {
        if (sum== S)
             cnt++;
        return;}
    else {
        queen(row+1,sum);
        queen(row+1,sum+arr[row]);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> S;
    for (int i=0; i<N; i++) {
        cin >> arr[i];
    }
    queen(0,0);
    if (S==0) cnt--;
    cout << cnt;
}