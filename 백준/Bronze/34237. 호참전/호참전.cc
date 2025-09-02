#include <bits/stdc++.h>
using namespace std;
int N,M;
pair<int,pair<int,int>> simul[100002];
pair<int,int> h[52];
int cnt=0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> h[i].first >> h[i].second;
    }
    for (int i=0; i<M ; i++) {
        cin >> simul[i].first >> simul[i].second.first >> simul[i].second.second;
    }
    for (int i=0; i<M ;i++) {
        int total = simul[i].first;
        int x= simul[i].second.first;
        int y= simul[i].second.second;
        int cnt=0;
        for (int j=0; j<N; j++) {
            if (h[j].first + h[j].second<=total) {
                if (x<=h[j].first) {
                    if (y<=h[j].second) {
                        cnt++;
                    }
                }
            }

        }
        cout << cnt << "\n";
    }
}
