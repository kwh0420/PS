#include <bits/stdc++.h>
using namespace std;
int n, k, t, m;
vector<int> cnt(102, 0);
vector<int> last_submitted(102, 0);
vector<vector<int>> scores(102, vector<int>(102,0));
vector<int> totalscores(102, 0);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> n >> k >> t >> m;
        for (int z = 0; z < m; z++) {
            int i,j,s;
            cin >> i >> j >> s;
            cnt[i] ++;
            last_submitted[i] =z;
            scores[i][j] =max(s,scores[i][j]);
        }
        for (int z = 1; z<=n;z++){
            for (auto i : scores[z]) {
                totalscores[z] += i;
            }
        }
        int myteam = totalscores[t];
        int result=1;
        for (int z = 1; z<=n; z++) {
            if (z==t)continue;
            if (totalscores[z] > myteam) {
                result++;
            }
            else if (totalscores[z] == myteam) {
                if (cnt[z] < cnt[t]) {
                    result++;
                }
                else if (cnt[z]==cnt[t]) {
                    if (last_submitted[z] < last_submitted[t]) {
                        result++;
                    }
                }
            }
        }
        cout << result << "\n";
        cnt.assign(102, 0);
        last_submitted.assign(102, 0);
        totalscores.assign(102, 0);
        scores.assign(102, vector<int>(102,0));
    }
}
