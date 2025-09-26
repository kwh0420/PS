#include <bits/stdc++.h>
using namespace std;
int truck[1002];
int weightsum=0;
int idx=0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,L,w;
    cin>>n>>w>>L;
    queue<int> q;
    for(int i=0;i<w;i++) {
        q.push(0);
    }
    for (int i=0; i<n; i++) {
        cin >> truck[i];
    }
    int time=0;
    while(!q.empty()) {
        time ++;
        weightsum-=q.front();
        q.pop();
        if (idx<n&&truck[idx]+weightsum<=L) {
            weightsum+=truck[idx];
            q.push(truck[idx]);

            idx++;
        }
        else if (idx<n){
            q.push(0);
        }
    }
    cout << time << "\n";
}