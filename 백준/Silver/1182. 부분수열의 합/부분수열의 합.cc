#include <bits/stdc++.h>
using namespace std;
int visited_col[21];
int result[21];
int arr[21];
int N;
int S;
int cnt=0;
void queen(int row,int sum) {
    if (row == N) {// base condition, 이거 없으면 무한루프 
        if (sum== S)
             cnt++;
        return;}
    else {
        queen(row+1,sum); //어차피 무조건 다음 row를 방문하므로 visited배열써서 백트래킹해줄 필요가 없음.
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
    if (S==0) cnt--; //공집합처리
    cout << cnt;

}
