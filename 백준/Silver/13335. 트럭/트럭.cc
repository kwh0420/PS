#include <bits/stdc++.h>
using namespace std;
int n,w,L;
int truck_weight[1002];
int indexindex=0;
int weight_sum=0;
queue<pair<int,int>> q;
int main() {
    cin >> n >> L >> w;
    for (int i = 0; i < n; i++) {
        cin >> truck_weight[i];
    }
    int time=0;
    q.push({0,truck_weight[0]});
    weight_sum+=truck_weight[indexindex++];
    while (!q.empty()) {
        time++;

        
        if (time-q.front().first>=L) {
            weight_sum-=q.front().second;
            q.pop();
        }
        if (indexindex == n) {
            continue;
        }
        if (q.size()<L) {
            if (weight_sum+truck_weight[indexindex]<=w) {
                q.push({time,truck_weight[indexindex]});
                weight_sum+=truck_weight[indexindex];
                indexindex ++;
            }
        }
    }
    cout <<time+1;
}