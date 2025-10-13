#include <bits/stdc++.h>
using namespace std;
map<int,int> tree[12][12]; // 나이와 개수는 int 범위로 충분합니다.
int cur_energy[12][12];
int plus_energy[12][12];
int N,M,K;
int row_dir[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int col_dir[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> plus_energy[i][j];
            cur_energy[i][j] = 5;
        }
    }
    for (int i=0; i< M; i++) {
        int r,c,z;
        cin >> r >> c >> z;
        tree[r-1][c-1][z]++;
    }
    
    for (int t=0; t<K; t++){
        int nxt_energy[12][12] = {0};

        // 봄 (Spring)
        for (int i=0; i< N; i++) {
            for (int j=0; j<N; j++) {
                if (tree[i][j].empty()) continue;
                map<int,int> temp;
                for (auto const& [age,cnt] : tree[i][j]) {
                    if ((long long)age * cnt > cur_energy[i][j]) {
                        int p = cur_energy[i][j]/age;
                        if (p > 0) temp[age+1]+=p;
                        cur_energy[i][j]-=age * p;
                        int remain = cnt-p;
                        nxt_energy[i][j]+=(age/2)*remain;

                        // 양분이 고갈되었으므로, 이 칸의 나머지 나무는 모두 죽음
                        // C++17 map은 순서를 보장하므로, 현재 iterator 다음부터 순회하면 됨
                        auto it = tree[i][j].find(age);
                        for(auto z = next(it); z != tree[i][j].end(); ++z) {
                            nxt_energy[i][j] += (z->first / 2) * z->second;
                        }
                        goto spring_end_cell; // 해당 칸의 봄 시뮬레이션 종료
                    }
                    else {
                        cur_energy[i][j] -=age*cnt;
                        temp[age+1]+=cnt;
                    }
                }
                spring_end_cell:;
                tree[i][j].swap(temp);
            }
        }

        // 여름 & 가을(분리된 처리) & 겨울
        vector<pair<int, int>> new_trees_locs; // 번식할 나무 위치만 저장

        for (int i=0; i< N; i++) {
            for (int j=0; j<N; j++) {
                // 여름
                cur_energy[i][j]+=nxt_energy[i][j];

                // 가을 (읽기 단계) - 번식할 나무가 있는 위치만 저장
                for (auto const& [age,cnt] : tree[i][j]) {
                    if (age%5==0) {
                        for(int k=0; k<cnt; ++k) new_trees_locs.push_back({i, j});
                    }
                }
            }
        }
        
        // 가을 (쓰기 단계) - 저장된 위치를 기반으로 한 번에 번식
        for(auto const& loc : new_trees_locs) {
            for(int k=0; k<8; ++k) {
                int nrow = loc.first + row_dir[k];
                int ncol = loc.second + col_dir[k];
                if (0<=nrow && nrow<N && 0<=ncol && ncol<N) {
                    tree[nrow][ncol][1]++;
                }
            }
        }

        // 겨울
        for (int i=0; i< N; i++) {
            for (int j=0; j<N; j++) {
                cur_energy[i][j]+=plus_energy[i][j];
            }
        }
    }
    
    long long int cnt=0;
    for (int i=0; i< N; i++) {
        for (int j=0; j<N; j++) {
            for (auto const& [d,f] : tree[i][j]) {
               cnt+=f;
            }
        }
    }
    cout << cnt;
}