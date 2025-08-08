#include <bits/stdc++.h>
using namespace std;
int visited_col[17];
int visited_right_diagonal[35];
int visited_left_diagonal[35];
int N;
int cnt=0;
void queen(int row) {
    if (row == N) {
        cnt++;
        return ;
    }
    else {
        for (int i=0; i<N; i++) {
            if (visited_col[i] || visited_right_diagonal[row-i+N-1] || visited_left_diagonal[i+row] ) 
                continue;
            visited_col[i] = 1;
            visited_right_diagonal[row-i+N-1] = 1;
            visited_left_diagonal[i+row] = 1;
            queen(row+1);
            visited_col[i] = 0;
            visited_right_diagonal[row-i+N-1] = 0;
            visited_left_diagonal[i+row] = 0;
        }
    }
}
int main() {
    cin >> N;
    queen(0);
    cout << cnt << endl;
}