#include <bits/stdc++.h>
using namespace std;
#define ll long long
int arr[2188][2188];
int N;
int row_dir[3] = {0,1,2};
int col_dir[3] = {0,1,2};
int result[3];
bool compare(int start_row,int start_col,int N) { //처음엔 solve내에 전부다 써주었으나, 비교하는 부분만 함수로 빼주면 코드가 좀더 간결해짐. 그러나 성능면에선 별차이 없었음 8ms차이
    int value = arr[start_row][start_col];
    for (int i=start_row ; i<start_row +N ; i++) {
        for (int j=start_col; j<start_col+N ; j++) {
            if (arr[i][j]!=value) {
                return false;
            }
        }
    }
    return true;
}
void solve(int start_row,int start_col, int N) {
    int same=1;
    /* if (N==1) { 원래 이렇게 N==1일때의 base condition을 넣어줬으나, 어차피 N=1일때, 부분 배열의 모든 원소가 같으므로 compare
                    조건에 걸림. 그래서 N==1일떄의 base condition은 필요하지 않음.
     result[arr[start_row][start_col]+1]++;
     return;
     } */

    if (compare(start_row,start_col,N)) {
        result[arr[start_row][start_col]+1]++;
    }
    else {
        int nN= N/3;
        for (int i=0; i<3; i++) {
            for (int j=0; j<3 ; j++) {
                int nrow = start_row + row_dir[i]*nN;
                int ncol = start_col + col_dir[j]*nN;
                solve(nrow,ncol,nN); //이부분이 재귀의 핵심, 만약 9부분이 같지 않으면 쪼개서 9부분 내에서 다시 또 비교를 시킴
            }
        }
    }


}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); // 이두분을 넣느냐 마느냐에 따라 600ms나 차이가 났음. 귀찮다고 생각하지 말고 무조건 넣는게 좋을듯. (900ms->300ms
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
    solve(0,0,N);
    for (int i=0; i<3; i++) {
        cout << result[i];
        cout <<'\n';
    }

}

